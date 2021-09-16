//You are given with an array of integers and an integer K.
// You have to find and print the count of all such pairs which have difference K.
//Note: Take absolute difference between the elements of the array.



//put all element of array into hashmap and maintain their count
//traverse the array again and check if any element is present in map which can result diff of k
//if it is present update count by multiplying frequency of both element
//after updating count remove that element from map

int pair_diff_k(int*a,int n,int k){
  unordered_map<int,int> m;
  for(int i=0;i<n;i++){
    m[a[i]]++;
  }
  int count=0;
  for(int i=0;i<n;i++){
    if(m.count(a[i]-k)>0){
      count+=(m[a[i]]*m[a[i]-k]);
    }
    if(m.count(a[i]+k)>0){
      count+=(m[a[i]]*m[a[i]+k]);
    }
    m[a[i]]=0;
  }
  return count;
}
