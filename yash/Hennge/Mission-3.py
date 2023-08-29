import httplib2
import hmac
import hashlib
import time
import sys
import struct
import json
import requests

root = "https://api.challenge.hennge.com/challenges/003"
content_type = "application/json"
userid = "yash01012002@gmail.com"
name = "HENNGECHALLENGE003"
shared_secret = userid + name

timestep = 30
T0 = 0

def HOTP(K, C, digits = 10):
    K_bytes = str.encode(K)
    C_btyes = struct.pack(">Q", C)
    hmac_sha512 = hmac.new(key = K_bytes, msg = C_btyes, digestmod=hashlib.sha512).hexdigest()
    return Truncate(hmac_sha512)[-digits:]

def Truncate(hmac_sha512):
    offset = int(hmac_sha512[-1], 16)
    binary = int(hmac_sha512[(offset*2): ((offset*2)+8)], 16) & 0x7FFFFFF
    return str(binary)

def TOTP(K, digits = 10, timeref = 0, timestep = 30):
    C = int(time.time() - timeref) // timestep
    return HOTP(K, C, digits = digits)

data = {"github_url" : "https://gist.github.com/elli0t-yash/347d68832bf53493958b9230f1cac77f"}

password = TOTP(shared_secret, 10, T0, timestep).zfill(10)

# h = httplib2.Http()
# h.add_credentials(userid, password)
# header = {"Authorization" : "OATH TOKEN", "content-type": "application/json"}
# resp, content = h.request(root, "POST", headers = header, body = json.dumps(data))
# print(resp)
# print(content)

headers = {
    "Authorization" : f"Bearer {password}",
    "Content-Type" : "application/json"
}

response = requests.post(root, headers = headers, json = data)

print(response.status_code)
print(response.text)
