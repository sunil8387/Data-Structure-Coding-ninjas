//You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
//Note :Input arrays/lists can contain duplicate elements.



void intersection(int*a,int n,int*b,int m){
  unordered_map<int,int> m1;
  for(int i=0;i<n;i++){
    m1[a[i]]++;     //first we store a1 array in map
  }
  for(int i=0;i<m;i++){
    if(m1.count(b[i])>0){    //then we check if b1 array is present in map or not
      cout<<b[i]<<" ";   // if yes then we will print that element and dec its count from map
      m1[b[i]]--;
      if(m1[b[i]]==0){  // if the count become 0 then we will remove the element from map
        m1.erase(b[i]);
      }
    }
  }
  return;
}
