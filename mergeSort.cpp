class Solution {
public:
	void mergeSort(vector<int> &num){
		int n = num.size();
		if(n<2) return;
		vector<int> left,right;
		auto it = next(num.begin(),n/2);
		copy(num.begin(),it,back_inserter(left));
		copy(it,num.end(),back_inserter(right));
		mergeSort(left);
		mergeSort(right);
		num = merge(left,right);

	}
	vector<int> merge(vector<int> &A,vector<int> &B) {
	    vector<int> result;
		int i = 0,j=0;
	    while(i<A.size()&& j<B.size()){
	    	if(A[i]>B[j]) {
	    		result.push_back(B[j]);
	            j++;}
	        else{
	            result.push_back(A[i]);
	            i++;
	            }
	    }
	    if(i<A.size())
	    	copy(next(A.begin(),i),A.end(),back_inserter(result));
	    if(j<B.size())
	    	copy(next(B.begin(),j),B.end(),back_inserter(result));
		return result;
	    }

};
