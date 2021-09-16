//Given a string S, you need to remove all the duplicates.
// That means, the output string should contain each character only once.
// The respective order of characters should remain same, as in the input string.


//put all element of array in hashmap
// while putting check if the element already exist in hashmap if so don't do anything and move to next element
//else put that element in hashmap as well as in vector which has to be returned
vector<char> extract_unique(char* a,int n){
  vector<char>v;
  unordered_map<char,bool> m;
  for(int i=0;i<n;i++){
    if(m.count(a[i]) >0){
      continue;
    }
    m[a[i]]=true;
    v.push_back(a[i]);
  }
   return v;
}
