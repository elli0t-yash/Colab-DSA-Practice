import requests
import json
import hmac
import hashlib
import time

def TOTP(secret_key, interval = 30):
    current_time = int(time.time()) // interval
    message = current_time.to_bytes(8, byteorder="big")
    hmac_digest = hmac.new(secret_key, message, hashlib.sha512).digest()
    offset = hmac_digest[-1] & 0x0F
    OTP = ((hmac_digest[offset] & 0x7F) << 24 | (hmac_digest[offset + 1] & 0xFF) << 16 | (hmac_digest[offset + 2] & 0xFF) << 8 | (hmac_digest[offset + 3] & 0xFF))
    return OTP % 10**10

userid = "yash01012002@gmail.com"
gist_url = "https://gist.github.com/elli0t-yash/347d68832bf53493958b9230f1cac77f"
solution_lang = "Python"

shared_secret_key = userid.encode() + b"HENNGECHALLENGE003"

TOTP_Password = TOTP(shared_secret_key)

JSON_Data = {
    "github_url": gist_url,
    "contact_email": userid,
    "solution_language": solution_lang
}
JSON_String = json.dumps(JSON_Data)

URL = "https://api.challenge.hennge.com/challenges/003"

headers = {
    "Content-Type": "application/json"
}

auth = (userid, str(TOTP_Password))
response = requests.post(URL, headers=headers, data=JSON_String, auth=auth)

print(response.text)