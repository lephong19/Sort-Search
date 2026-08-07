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
void pushBackArr(sinhVien *&a,int &n , sinhVien x)  
{
    n=(a==NULL)? 1 : n+1;
    sinhVien *newArr=new sinhVien[n] ;
    for(int i=0;i <n-1; i++)
    {
        newArr[i]=a[i];
    }
    newArr[n-1]=x;
    delete[]a;
    a=newArr;
}
void inputFromFile(list &l) 
{
    ifstream fin ("sinhVien.txt") ;
    if(!fin)
    {
        cout << "Khong mo duoc file";
        return;
    }
    sinhVien x ;
    while(fin >> x.mssv)
    {
        fin.ignore() ;
        getline(fin,x.hoTen,'#');
        fin.getline(x.ngaySinh,11,'#');
        fin.getline(x.queQuan,100,'#');
        fin >> x.gpa;
        pushBackArr(l.ds,l.n,x);

    }
    fin.close() ;
}
void sort(list &l) 
{
    for(int i=0; i < l.n-1; i++) 
    {
        int min_pos=i;
        for(int j=i+1; j < l.n; j++) 
        {
            if(l.ds[min_pos].hoTen>l.ds[j].hoTen)
            min_pos=j;
        }
        swap(l.ds[i],l.ds[min_pos]) ;
    }
}
int timKiemNhiPhan(list l, const string &name)
{
    int le=0;
    int ri=l.n-1;
    while(le <= ri) 
    {
        int m=(le+ri)/2;
        if(l.ds[m].hoTen==name)
        {
            return m;
        }else if(l.ds[m].hoTen>name)
        {
            ri=m-1;
        }else{
            le=m+1;
        }
    }
    return -1;
}

int main() 
{
    list l;
    init(l);
    inputFromFile(l) ;
    xuatDanhSach(l) ;
    sort(l);

    cout << endl ;
    cout << "TIM KIEM NHI PHAN" << endl;
    int pos=timKiemNhiPhan(l,"Nguyen Van An");
    if(pos!=-1)
    {
        xuatSinhVien(l.ds[pos]);
    }else{
        cout << "Khong Tim Thay";
    }
    return 0;
}