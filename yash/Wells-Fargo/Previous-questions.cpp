#include<bits/stdc++.h>
using namespace std;

class deliveryPartner {
    public:
        int salary;
        int initialDistance;
        bool bonusAdded;

        deliveryPartner(int s, int id) : salary(s), initialDistance(id), bonusAdded(false) {}
}; 

int calculateTotalSalary(vector<deliveryPartner>& deliveryPartners) {
    int totalSalary = 0;
    for (auto& dp : deliveryPartners) {
        totalSalary += dp.salary;
    }
    return totalSalary;
}

int processQueries(vector<deliveryPartner>& deliveryPartners, int maxDistance, int bouns) {
    int queryType;
    cin>>queryType;

    if(queryType == 0) {
        return calculateTotalSalary(deliveryPartners);
    } else if(queryType == 1) {
        int deliveryPartnerIndex, newDistance;
        cin>>deliveryPartnerIndex>>newDistance;

        if(!deliveryPartners[deliveryPartnerIndex].bonusAdded) {
            deliveryPartners[deliveryPartnerIndex].initialDistance += newDistance;

            if(deliveryPartners[deliveryPartnerIndex].initialDistance > maxDistance) {
                deliveryPartners[deliveryPartnerIndex].salary += bouns;
                deliveryPartners[deliveryPartnerIndex].bonusAdded = true;
            }
        }

    }
}


//LRU-Cache (deque-hashmap)
    class LRUCache {
    public:
        int cacheSize;
        map<int, int> mp;
        deque<int> dq;

        LRUCache(int capacity) {
            mp.clear();
            dq.clear();
            cacheSize = capacity;
        }

        int get(int key) {
            if(mp.find(key) == mp.end()) {
                return -1;
            } else {
                deque<int>::iterator it = dq.begin();
                while(*it != key) {
                    it++;
                }

                dq.erase(it);
                dq.push_front(key);

                return mp[key];
            }
        }
        
        void put(int key, int value) {
            if(mp.find(key) == mp.end()) {
                if(cacheSize == dq.size()) {
                    int last = dq.back();
                    dq.pop_back();
                    mp.erase(last);
                } 
            } else {
                deque<int>::iterator it = dq.begin();
                while(*it != key) {
                    it++;
                }

                dq.erase(it);
                mp.erase(key);
            }

            dq.push_front(key);
            mp[key] = value;
        }
    };

// LRU Cache (dll + hashmap)
class LRUCache {
public:
    class node {
        public: 
            int val;
            int key;
            node* prev;
            node* next;
            node(int k, int v) {
                key = k;
                val = v;
            }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cacheSize;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cacheSize = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* first) {
        node *t = head->next;
        head->next = first;
        first->prev = head;
        t->prev = first;
        first->next = t;
    }

    void deleteNode(node* nod) {
        node* delpre = nod->prev;
        node* delnex = nod->next;
        delpre->next = delnex;
        delnex->prev = delpre;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            node* t = mp[key];
            int ans = t->val;
            mp.erase(key);
            deleteNode(t);
            addNode(t);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            node* t = mp[key];
            mp.erase(key);
            deleteNode(t);
        } else if(mp.size() == cacheSize) {
            node* t = tail->prev;
            mp.erase(t->key);
            deleteNode(t);
        }
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};



int main() {
    int no_of_delivery_partners, maxDistance, bonus;
    cin>>no_of_delivery_partners>>maxDistance>>bonus;

    vector<deliveryPartner> deliveryPartners;

    for(int i = 0; i < no_of_delivery_partners; i++) {
        int salary, initialDistance;
        cin>>salary>>initialDistance;

        deliveryPartners.push_back(deliveryPartner(salary, initialDistance));
    }

    
    processQueries(deliveryPartners, maxDistance, bonus);
    
    return 0;
}