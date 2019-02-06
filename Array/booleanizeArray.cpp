#include <iostream>

int main(int argc, char *argv[]) {
	long long T, r, c, **arr, *row, *col;
	std::cin>>T;
	while(T--) {
		std::cin>>r>>c;
		arr = new long long*[r];
		for(long long i=0;i<r;i++)
			arr[i] = new long long[c];
		row = new long long[r];
		col = new long long[c];
		for(long long i=0;i<r;i++)
			for(long long j=0;j<c;j++){
				std::cin>>*(*(arr+i)+j);
				if(arr[i][j] == 1){
					row[i] = 1;
					col[j] = 1;
				}
			}
		for(long long i=0;i<r;i++){
			for(long long j=0;j<c;j++)
				if(row[i] == 1 || col[j] == 1)
					std::cout<<"1 ";
				else
					std::cout<<"0 ";
			std::cout<<std::endl;
		}
		for(long long i=0;i<r;i++)
			delete[] arr[i];
		delete[] arr;
	}
	return 0;
}