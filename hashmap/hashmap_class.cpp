#include<iostream>
#include <string>
using namespace std;

template <typename V>
class mapnode{
public:
  string key;
  V value;
  mapnode* next;

  mapnode(string key,V  value){
    this->key=key;
    this->value=value;
    next=NULL;
  }
  ~mapnode(){
    delete next;
  }
};

template<typename V>
class ourmap{
public:
  mapnode<V>** bucket;
  int count;
  int bucketsize;

  ourmap(){
    bucketsize=5;
    bucket=new mapnode<V>*[bucketsize];
    count=0;
    for(int i=0;i<bucketsize;i++){
      bucket[i]=NULL;
    }
  }
private:
  int get_bucket_index(string key){
    int hash_value=0,curr_value=1;
    for(int i=key.length()-1;i>=0;i--){
      hash_value+=key[i]*curr_value;
      hash_value=hash_value%bucketsize;
      curr_value*=17;
      curr_value=curr_value%bucketsize;
    }

    return hash_value%bucketsize;
  }

  void rehash(){
    mapnode<V>** temp=bucket;
    bucket=new mapnode<V>*[2*bucketsize];
    for (int i = 0; i <2*bucketsize; i++) {
      bucket[i]=NULL;
    }
    int old_count=bucketsize;
    bucketsize*= 2;
    count=0;
    for(int i=0;i<old_count;i++){
      mapnode<V>* head=temp[i];
      while (head!=NULL) {
        string key=head->key;
        V value=head->value;
        insert(key,value);
        head=head->next;
      }
    }
    for(int i=0;i<old_count;i++){
      mapnode<V>* head=temp[i];
      delete head;
    }
    delete [] temp;
  }


public:
  double get_load(){
    return (1.0*count)/bucketsize;
  }

  int size(){
    return count;
  }
  void insert(string key,V value){
    int bucketindex=get_bucket_index(key);
    mapnode<V>* head=bucket[bucketindex];
    while(head!=NULL){
      if (head->key==key){
          head->value=value;
          return;
      }
      head=head->next;
    }
    head=bucket[bucketindex];
    mapnode<V>* node=new mapnode<V>(key,value);
    node->next=head;
    bucket[bucketindex]=node;
    count++;
    double load_factor=(1.0*count)/bucketsize;
    if(load_factor>0.7){
       rehash();
    }

  }

  V delete_key(string key){  // delete the key and return its value
    int bucketindex=get_bucket_index(key);
    mapnode<V>* head=bucket[bucketindex];
    mapnode<V>* prev=NULL;
    while (head!=NULL) {
      if(head->key==key){
        if(prev==NULL){
          bucket[bucketindex]=head->next;
        }
        else{
          prev->next=head->next;
        }
        V value=head->value;
        head->next=NULL;
        delete head;
        count--;
        return value;
      }
      prev=head;
      head=head->next;
    }
    return 0;
  }
  V get_value(string key){
    int bucketindex=get_bucket_index(key);
    mapnode<V>* head=bucket[bucketindex];
    while (head!=NULL) {
      if(head->key==key){
        return head->value;
      }
      head=head->next;
    }
    return 0;
  }
};



int main(int argc, char const *argv[]) {
  ourmap<int> m;
  for (int i=0 ; i <10 ; i++) {
    char c='0'+i;
    string key="abc";
    key=key+c;
    int value=i+1;
    m.insert(key,value);
    cout<<m.get_load()<<endl;
  }
  cout<<m.delete_key("abc3")<<endl;
  cout<<m.delete_key("abc8")<<endl;
  cout<<m.delete_key("abx")<<endl;
  for (int i=0 ; i <10 ; i++) {
    char c='0'+i;
    string key="abc";
    key=key+c;
    cout<<key<<":"<<m.get_value(key)<<endl;
  }

  cout<<"size"<<m.size()<<endl;





  return 0;
}
