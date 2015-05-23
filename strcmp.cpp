class Solution {
public:
	int strcmp(string a,string b){
		int n = min(a.size(),b.size());
		for(int i = 0;i<n;i++){
			if(a[i]<b[i])
				return -1;
			if(a[i]>b[i])
				return 1;
		}
		if(a.size()==b.size()) return 0;
		if(a.size()>b.size()) return 1;
		else return -1;
	}
	int strcmp(const char* a,const char* b){

		while(*a && *b && *a == *b){
			a++;
			b++;
		}
		if(*a > *b) return 1;
		if(*a < *b) return -1;
		return 0;
	}
};
