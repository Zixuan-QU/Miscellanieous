class Solution {
public:
	void quickSort(vector<int> num){
		quickSort(num,0,num.size()-1);
	}
	void quickSort(vector<int> &num,int low, int up){
		if(up <= low) return;
		int i = partition(num,low,up);
		quickSort(num,low,i-1);
		quickSort(num,i+1,up);
	}
	int partition(vector<int> &num,int low, int up){
		if(up==low) return low;
		int i = low-1, j = low;
		for(;j<up;j++){
			if(num[j]<=num[up]){
				i++;
				swap(num[i],num[j]);
			}

		}
		swap(num[up],num[++i]);
		return i;


	}
};
