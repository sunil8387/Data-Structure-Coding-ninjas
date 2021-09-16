//given an array of integer you need to remove duplicate intergers from that array

// store element of array into a map and while storing check if the element is already prsent in map
//if yes then don't do anything and if no then store that element in map and push it
// to the vector and at last return that array.
vector<int> remove_duplicate(int*a,int n){
  vector<int> v;
  unordered_map<int,bool> seen;
  for(int i=0;i<n;i++){
    if(seen.count(a[i])>0){
      continue;
    }
    seen[a[i]]=true;
    v.push_back(a[i]);
  }
  return v;
}
