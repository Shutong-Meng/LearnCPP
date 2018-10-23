#include<vector>
#include<iostream>
using namespace std;

int binarySearch(vector<int> a,int key)
{
	int mid=0;
	int start=0;
	int end=a.size()-1;
	if(end!=key)
		return -1;
	while(start<=end)
	{

		mid=(end-start)/2+start;
		cout<<mid<<"hi"<<'\n';
		if(start==end)
			break;
		if(a[mid]==key)
			end=mid;
		else
			start=mid+1;

	}
	return mid;
}

int main()
{
	vector<int> a;
	for(int i=0;i<6;i++)
	a.push_back(0);
    for(int i=6;i<10;i++)
	a.push_back(1);
	cout<<binarySearch(a,1);//6
	return 0;
}