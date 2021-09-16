//You are given an array of integers that contain numbers in random order.
//Write a program to find and return the number which occurs the maximum times in the given input.
//If two or more elements contend for the maximum frequency, return the element which occurs in the array first

int max_ocurring(int*a,int n){
  unordered_map<int,int> m;
  for(int i=0;i<n;i++){     // store element of array in a mop
    m[a[i]]++;
  }
  int max=INT_MIN,ans;
  //itrate over element of map and check their value corresponding to key element
  // if value is greater than max value update max and store its key within some varible and return it
  
  unordered_map<int,int>::iterator it=m.begin();
  while (it!=m.end()) {
    if(it->second>max){
      max=it->second;
      ans=it->first;
    }
    it++;
  }
  return ans;
}
