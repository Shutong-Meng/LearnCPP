#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
       
    		for(int size=s.length();size>0;size--)
    		{
    			for(int head=0,tail=head+size-1;tail<s.length();head++,tail++)//随着长度的递减列举所有子字符串
    			{
    				if(checkPalindrome(s,head,tail))
    					return s.substr(head,tail-head+1);//取从下标head开始长度未tail-head+1的子字符串
    			}

    		}
    		return s.substr(0,1);
        
    }
    
    
    bool checkPalindrome(string s, int head, int tail)//判断s的子字符串是否为回文
    {
    	while(head<=tail)
    	{
    		if(s[head]!=s[tail])
    			return false;
    		head++;
    		tail--;
    	}

    	return true;
    }
        
    
};

