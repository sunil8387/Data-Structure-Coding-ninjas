//Given an array consisting of positive and negative integers,
// find the length of the longest subarray whose sum is zero.


int longest_subset(int*a,int n){
  unordered_map<int,int> m;
  int sum=0,max_lenght=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
    if(max_lenght==0&&a[i]==0){
      max_lenght=1;
    }
    if(sum==0){
      max_lenght=i+1;
    }
    if(m.count(sum)>0){
      max_lenght=max(max_lenght,i-m[sum]);
    }
    else{
      m[sum]=i;
    }
  }
  return max_lenght;
}
