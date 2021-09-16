//You are given an array of unique integers that contain numbers in random order.
// You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
//You need to return the output array which contains starting and ending element.
// If the length of the longest possible sequence is one, then the output array must contain only single element.

int* longest_sequence(int*a,int n){
  unordered_map<int,bool> m;
  for(int i=0;i<n;i++){
    m[a[i]]=true;
  }
  int maxlenght=0,start,end,lenght,s,e;
  for(int i=0;i<n;i++){
    if(m[a[i]]=true){
      lenght=1;
      s=a[i];
      e=a[i];
      int j=1;
      while(m.count(a[i]+j)>0){
        lenght++;
        e=a[i]+j;
        m[a[i]+j]=false;
        j++;
      }
      j=1;
      while (m.count(a[i]-j)>0) {
        lenght++;
        s=a[i]-j;
        m[a[i]-j]=false;
        j++;
      }
      m[a[i]]=false;
    }
    if(lenght>maxlenght){
      maxlenght=lenght;
      start=s;
      end=e;
    }
  }
  static int b[2];
  b[0]=start;
  if(end==start){
    return b;
  }
  b[1]=end;
  return b;
}
