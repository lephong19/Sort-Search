#include <iostream>
#include <fstream>
#include <string>
using namespace std ;
struct sinhVien{
    int mssv;
    string hoTen;
    char queQuan[100];
    char ngaySinh[11];
    float gpa;
};
void xuatSinhVien(sinhVien sv) 
{
    cout << "-------------------------" << endl;
    cout << "MSSV: " << sv.mssv << endl;
    cout << "Ho Ten: " << sv.hoTen << endl ;
    cout << "Ngay Sinh: "  << sv.ngaySinh << endl ;
    cout << "Que Quan: " << sv.queQuan << endl ;
    cout << "GPA: " << sv.gpa << endl ;
    cout << "-------------------------" << endl;
}
struct list{
    sinhVien *ds;
    int n;
};
void init(list &l) 
{
    l.ds=NULL;
    l.n=0;
}
void xuatDanhSach(list l) 
{
    if(l.n==0)
    {
        cout << "DS RONG";
        return;
    }
    for(int i=0; i < l.n; i++) 
    {
        xuatSinhVien(l.ds[i]) ;
    }
}
void pushBackArr(sinhVien *&a , int &n , sinhVien x) 
{
    n=(a==NULL)?1:n+1;
    sinhVien *newArr=new sinhVien[n];
    for(int i=0; i < n-1;i++)
    {
        newArr[i]=a[i];
    }
    newArr[n-1]=x;
    delete[]a;
    a=newArr;
}
void inputFromFile(list &l) 
{
    ifstream fin("sinhVien.txt");
    if(!fin)
    {
        cout << "Khong Mo Duoc File";
        return;
    }
    sinhVien x;
    while(fin >> x.mssv){
        fin.ignore();
        getline(fin,x.hoTen ,'#');
        fin.getline(x.ngaySinh,11,'#');
        fin.getline(x.queQuan,100,'#');
        fin >> x.gpa;
        pushBackArr(l.ds,l.n,x) ;
    }
    fin.close() ;
}
void sapXepChen(list &l)
{
    for(int i=1; i < l.n; i++) 
    {
        sinhVien key=l.ds[i];
        int pos=i-1;
        while(pos >= 0 && l.ds[pos].gpa>key.gpa)
        {
            l.ds[pos+1]=l.ds[pos];
            pos--;
        }
        l.ds[pos+1]=key;
    }
}

int main() 
{
    list l;
    init(l) ;
    inputFromFile(l) ;
    sapXepChen(l) ;
    xuatDanhSach(l) ;
    return 0;
}