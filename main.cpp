#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
//ifstream testin("test.txt");
//ofstream testout("out.txt");
//ofstream adat("a.txt");
//ofstream bdat("b.txt");
int main() {
    int times,tmp=0,le,ls,ai,bi;
    string a,b,ans="",ws;
    cin>>times;
    //times=1;
    for (int y=0; y<times; y++) {
        ans="";
        cin>>a>>b;
        //a="";   //used for testing
        //b="";
        //for (int u=0; u<10000; u++) {
            //a.push_back('9');
            //b.push_back('8');
        //}
        //adat<<a;
        //bdat<<b;
        if (a.length()>b.length()) {
            le=(int)b.length();
            ls=(int)a.length();
            ai=(int)a.length()-1;
            bi=(int)b.length()-1;
        }else{
            le=(int)a.length();
            ls=(int)b.length();
            ai=(int)a.length()-1;
            bi=(int)b.length()-1;
        }
        for (int i=le-1; i>=0; i--) {
            if ((a[ai]-'0')+(b[bi]-'0')+tmp>9) {
                ans.insert(0, to_string(((a[ai]-'0')+(b[bi]-'0')+tmp)%10));
                tmp=((a[ai]-'0')+(b[bi]-'0'))/10;
            }else{
                ans.insert(0, to_string(tmp+(a[ai]-'0')+(b[bi]-'0')));
                tmp=0;
            }
            ai--;
            bi--;
        }
        ls=le;
        if (a.length()<b.length()) {
            le=(int)b.length();
            ws="b";
        }else{
            le=(int)a.length();
            ws="a";
        }
        for (int o=le-ls-1; o>=0; o--) {
            if (tmp!=0) {
                if (ws=="b") {
                    ans.insert(0, to_string((tmp+b[o]-'0')%10));
                    tmp=(tmp+b[o]-'0')/10;
                }else{
                    ans.insert(0, to_string((tmp+a[o]-'0')%10));
                    tmp=(tmp+a[o]-'0')/10;
                }
            }else{
                if (ws=="a") {
                    ans.insert(0, to_string(a[o]-'0'));
                }else{
                    ans.insert(0, to_string(b[o]-'0'));
                }
            }
        }
        while (tmp!=0) {
            ans.insert(0, to_string(tmp%10));
            tmp=tmp/10;
        }
        cout<<ans<<endl;
        //testout<<ans<<endl;
    }
    return 0;
}
