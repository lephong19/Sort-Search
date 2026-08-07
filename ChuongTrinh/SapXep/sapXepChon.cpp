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
void pushBackArr(sinhVien *&a , int &n , sinhVien x)
{
    n=(a==NULL)?1:n+1;
    sinhVien *newArr=new sinhVien[n] ;
    for(int i=0; i < n-1; i++) 
    {
        newArr[i]=a[i];
    }
    newArr[n-1]=x;
    delete []a;
    a=newArr;
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
int cmp(sinhVien a,sinhVien b)
{
    return a.mssv-b.mssv;
}
void sapXepGiamDan(list &l) 
{
    for(int i=0; i < l.n-1; i++) 
    {
        int min_pos=1;
        for(int j=i+1; j <l.n; j++) 
        {
            if(l.ds[min_pos].mssv<l.ds[j].mssv) 
            {
                min_pos=j;
            }
        }
        swap(l.ds[i],l.ds[min_pos]);
    }
}
void sapXepCmp(list &l , int func(sinhVien,sinhVien)=cmp)
{
    for(int i=0; i < l.n-1; i++)
    {
        for(int j=i+1 ; j < l.n; j++) 
        {
            if(func(l.ds[i],l.ds[j])>0)
            {
                swap(l.ds[i],l.ds[j]);
            }
        }
    }
}
int main() 
{
    list l;
    init(l) ;
    inputFromFile(l);
    sapXepCmp(l) ;
    xuatDanhSach(l);
    return 0;
}