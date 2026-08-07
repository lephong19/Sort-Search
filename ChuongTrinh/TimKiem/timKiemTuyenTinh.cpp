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
void nhapSinhVien(sinhVien &sv) 
{
    cout << "Nhap MSSV: ";
    cin >> sv.mssv;
    cin.ignore() ;
    cout << "Nhap Ho Ten: " ;
    getline(cin , sv.hoTen) ;
    cout << "Nhap Ngay Sinh: ";
    cin >> sv.ngaySinh;
    cout << "Nhap Que Quan: ";
    cin >> sv.queQuan;
    cout << "Nhap GPA:" ;
    cin >> sv.gpa; 
}
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
void nhapDanhSach(list &l) 
{
    do{
        cout << "Nhap so luong sinh vien: " ;
        cin >> l.n;
    }while(l.n<0);
    l.ds=new sinhVien[l.n] ;
    for(int i=0; i < l.n; i++) 
    {
        nhapSinhVien(l.ds[i]);
    }
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
int timSinhVien(list l , const int &id) 
{
    if(l.n==0) 
    {
        cout << "isEmpty";
        return -1;
    }
    for(int i=0; i < l.n; i++) 
    {
        if(l.ds[i].mssv==id)
        {
            return i;
        }
    }
    return -1;
}
void timTheoTen(list l , const string &ten)
{
    
    if(l.n==0) 
    {
        cout <<"isEmpty";
        return;
    }
    bool timThay=false;
    for(int i=0; i < l.n; i++) 
    {
        if(l.ds[i].hoTen==ten)
        {
            timThay=true;
            xuatSinhVien(l.ds[i]);
        }
    }
    if(!timThay)
    {
        cout << "Khong Ton Tai Ten ";
    
    }
}
void inputFromFile(list &l) 
{
    ifstream fin ("sinhVien.txt");
    if(!fin)
    {
        cout << "Khong mo duoc file";
        return;
    }else{
        sinhVien x;
        while(fin >> x.mssv)
        {
            fin.ignore() ;
            getline(fin,x.hoTen,'#');
            fin.getline(x.ngaySinh,11,'#');
            fin.getline(x.queQuan,100,'#');
            fin >> x.gpa;
            fin.ignore();
                    pushBackArr(l.ds,l.n,x) ;

        }
    }
    fin.close();
}
int main() {
    list l;
    init(l) ;
   inputFromFile(l) ;
    xuatDanhSach(l) ;

    return 0;
}