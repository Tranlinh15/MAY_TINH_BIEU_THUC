#include<stdio.h>
#include<string.h>

#define MAX 100

void xoaKhoangTrang(char *s);  /*Ham xoa khoang trang ngay sau khi nhap chuoi*/
void xuli_b1(char *s);  /*Kiem tra xem ky tu dau tien cua chuoi co phai la ky tu '-'*/
void xuli_b2(char *s,int *a,int n);/*phan tich da thuc tu chuoi va luu cac he so tuong ung vao mot mang */
void xuli_b3(int *xuli, char *s,int *a,int n);/*tinh gia tri cua da thuc tai cac diem cho truoc va luu tru ket qua tuong ung vao cac phan tu cua mot mang so nguyen duoc truyen vao */
int max(int *a);/*tim bac cua da thuc, dua tren cac he so duoc luu tru trong mot mang so nguyen*/
int max_chia(double *a);/*tim bac cua da thuc, dua tren cac he so duoc luu tru trong mot mang so thuc*/
void cong(int *tong,int *s1_xuli,int *s2_xuli);/*cong hai da thuc voi nhau*/
void tru(int *hieu,int *s1_xuli,int *s2_xuli);/*tru hai da thuc voi nhau*/
void nhan(int *tich,int *s1_xuli,int *s2_xuli);/*nhan hai da thuc voi nhau*/
int kt_pt_dautien1(int *arr,int n); /*kiem tra xem mang so nguyen co phai la mot da thuc voi he so khong dung dau tien co khac khong*/
int kt_pt_dautien2(double *arr,int n);/*kiem tra xem mang so thuc co phai la mot da thuc voi he so khong dung dau tien co khac khong*/
void chia(double *thuong,double *du,int *s1_xuli,int *s2_xuli);/*Phep chia da thuc*/
int check1(int *a);/*kiem tra xem mang so nguyen co tat ca cac phan tu dau bang 0 hay khong.*/
int check2(double *a);/*kiem tra xem mang so thuc co tat ca cac phan tu dau bang 0 hay khong.*/
void hienthi1(int *arr);/*hien thi da thuc duoi dang chuoi. Da thuc dai dien boi mot mang so nguyen */
int dem(double n); /*dem so chu so khong dang ke sau dau thap phan cua mot so thuc*/
void hienthi2(double *arr); /*hien thi da thuc duoi dang chuoi. Da thuc dai dien boi mot mang so thuc*/



int main()  
{
    int a1[MAX];
    int a2[MAX];
    int s1_xuli[MAX];
    int s2_xuli[MAX];

    int tong[MAX];
    int hieu[MAX];
    int tich[MAX];
    double thuong[MAX];
    double du[MAX];
    for (int i=0;i<MAX;i++)
    {
        a1[i]=0;
        a2[i]=0;

        s1_xuli[i]=0;
        s2_xuli[i]=0;

        tong[i]=0;
        hieu[i]=0;
        tich[i]=0;
        thuong[i]=0;
        du[i]=0;
    }
    int n1=0;
    int n2=0;
    char s1[50];
    printf("Nhap da thuc 1: ");
    gets(s1);
    xoaKhoangTrang(s1);
    
    char s2[50];
    printf("Nhap da thuc 2: ");
    gets(s2);
    xoaKhoangTrang(s2);
    
    xuli_b3(s1_xuli,s1,a1,n1);
    xuli_b3(s2_xuli,s2,a2,n2);

   
    cong(tong,s1_xuli,s2_xuli);
    tru(hieu,s1_xuli,s2_xuli);
    nhan(tich,s1_xuli,s2_xuli);
    chia(thuong,du,s1_xuli,s2_xuli);




    printf("tong la: ");
    hienthi1(tong);
    printf("\nhieu la: ");
    hienthi1(hieu);
    printf("\ntich la: ");
    hienthi1(tich);
    printf("\nthuong la: ");
    hienthi2(thuong);
    printf("\ndu la: ");
    hienthi2(du);
    printf("\n");
    
}

void xoaKhoangTrang(char *s) 
{
    int i, j;
    for (i = 0; s[i]; i++) 
	{
        if (s[i] == ' ') 
		{
            for (j = i; s[j]; j++) 
			{
                s[j] = s[j+1];
            }
            i--;
        }
    }
}



void xuli_b1(char *s)
{
    if(s[0]!= '-')
    {
        char c='+';
        s[strlen(s)+1]='\0';
        for (int i=strlen(s);i>=0;i--)
        {
            s[i]=s[i-1];
            if (i==0)
            {
                s[i]=c;
            }
        }
    }
    
}

void xuli_b2(char *s,int *a,int n)
{
    xuli_b1(s);
    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]=='x')
        {
            if (s[i-1]=='+')
            a[n]=1;
            else if(s[i-1]=='-')
            a[n]=-1;
            n++;
            if (s[i+1]!='^')
            {
                a[n]=1;
                n++;
            }
        }
        if ((s[i]<='9' && s[i]>='0'))
        {
            int dem=0;
            int sum=0;
            while ((s[i]<='9' && s[i]>='0'))
            {
                sum=sum*10+(s[i]-'0');
                
                dem++;
                i++;
            }
            if (s[i-dem-1]=='-')
            {
                sum=-sum;
            }
            
            a[n]=sum;
            n++;
         
            if (s[i]=='x')
            {
                if (s[i+1]!='^')
                {
                    a[n]=1;
                    n++;
                }
            }

            if (s[i]!='x' && s[i-dem-1]!='^')
            {
                a[n]=0;
                n++;
            }
        }
    }
}

void xuli_b3(int *xuli, char *s,int *a,int n)
{
    xuli_b2(s,a,n);
    int i=0;
    while ( ! (a[i]==0 && a[i+1]==0) )
    {
        i+=2;
    }

    for (int j=0;j<i;j=j+2)
    {

        xuli[a[j+1]]=xuli[a[j+1]] + a[j];
    }
}

int max(int *a) 
{
    int max=0;
    for (int i=0;i<MAX;i++)
    {
        if (a[i]!=0 && max<i)
        {
            max =i;
        }
    }
    return max;
}

int max_chia(double *a) 
{
    int max=0;
    for (int i=0;i<MAX;i++)
    {
        if (a[i]!=0 && max<i)
        {
            max =i;
        }
    }
    return max;
}

void cong(int *tong,int *s1_xuli,int *s2_xuli)
{
    for(int i=0;i<100;i++)
    {
        tong[i]=s1_xuli[i]+s2_xuli[i];
    }
}

void tru(int *hieu,int *s1_xuli,int *s2_xuli)
{
    for(int i=0;i<100;i++)
    {
        hieu[i]=s1_xuli[i]-s2_xuli[i];
    }
}

void nhan(int *tich,int *s1_xuli,int *s2_xuli)
{
    for(int i=0;i<=max(s1_xuli);i++)
    {
        for (int j=0;j<=max(s2_xuli);j++)
        {
            tich[i+j]+=s1_xuli[i]*s2_xuli[j];
        }
       
    }
}

int kt_pt_dautien1(int *arr,int n)
{
    int i=0;
    while (arr[i]==0)
    {
        i++;
    }
    if (i!=n)
    return 0;
    return 1;
}

int kt_pt_dautien2(double *arr,int n)
{
    int i=0;
    while (arr[i]==0)
    {
        i++;
    }
    if (i!=n)
    return 0;
    return 1;
}

void chia(double *thuong,double *du,int *s1_xuli,int *s2_xuli)
{
    double tich_chia[MAX];
    double s1_xuli_chia[MAX];
    double s2_xuli_chia[MAX];
    

    for (int i=0;i<MAX;i++)
    {
        tich_chia[i]=0;
        s1_xuli_chia[i]=s1_xuli[i]*1.0;
        s2_xuli_chia[i]=s2_xuli[i]*1.0;
    }

    
    while(max_chia(s1_xuli_chia)>=max_chia(s2_xuli_chia))
    {
        
        double a=s1_xuli_chia[max_chia(s1_xuli_chia)]/s2_xuli_chia[max_chia(s2_xuli_chia)];
        
        int b=max_chia(s1_xuli_chia)-max_chia(s2_xuli_chia);
        
        thuong[b]=a;

        for (int i=0;i<MAX;i++)
        {
            tich_chia[i]=0; 
        }
        for (int i=0;i<=max_chia(s2_xuli_chia);i++)
        {
            tich_chia[i+b]+=thuong[b]*s2_xuli_chia[i];
        }
        for(int i=0;i<=max_chia(s1_xuli_chia);i++)
        {
            s1_xuli_chia[i]=s1_xuli_chia[i]-tich_chia[i];
        }
    }
    
    for (int i=0;i<=max_chia(s1_xuli_chia);i++)
    {
        du[i]=s1_xuli_chia[i]*1.0;
    }
}

int check1(int *a)
{
    for (int i=0;i<MAX;i++)
    {
        if (a[i]!=0)
        return 1;
    }
    return 0;
}

int check2(double *a)
{
    for (int i=0;i<MAX;i++)
    {
        if (a[i]!=0)
        return 1;
    }
    return 0;
}

void hienthi1(int *arr)
{
    
    if (check1(arr))
    {
        if (arr[0]!=0)
        {
            printf("%d",arr[0]);
        }

        if (kt_pt_dautien1(arr,1)==0)
        {
            if (arr[1]!=0)
            {
                if (arr[1]>0 )
                {
                    if (arr[1]!=1)
                    {
                        printf("+%dx",arr[1]);
                    }
                    else 
                    {
                        printf("+x");
                    }
                }
                else if (arr[1]<0)
                {
                    if (arr[1]!=-1)
                    {
                        printf("%dx",arr[1]);
                    }
                    else 
                    {
                        printf("-x");
                    } 
                }
            }
        }
        else
        {
            if (arr[1]!=0)
            {
                if (arr[1]>0 )
                {
                    if (arr[1]!=1)
                    {
                        printf("%dx",arr[1]);
                    }
                    else 
                    {
                        printf("x");
                    }
                }
                else if (arr[1]<0)
                {
                    if (arr[1]!=-1)
                    {
                        printf("%dx",arr[1]);
                    }
                    else 
                    {
                        printf("-x");
                    } 
                }
            }
        }
        
        for (int i=2;i<=max(arr);i++)
        {
            if (kt_pt_dautien1(arr,i)==0)
            {
                if (arr[i]!=0)
                {
                    if (arr[i]>0)
                    {
                        if (arr[i]!=1)
                        {
                            printf("+%dx^%d",arr[i],i);
                        }
                        else 
                        {
                            printf("+x^%d",i);
                        }
                    }        
                    else if (arr[i]<0)
                    {
                        if (arr[i]!=-1)
                        {
                            printf("%dx^%d",arr[i],i);
                        }
                        else 
                        {
                            printf("-x^%d",i);
                        } 
                        
                    }
                }
            }
            else
            {
                if (arr[i]!=0)
                {
                    if (arr[i]>0)
                    {
                        if (arr[i]!=1)
                        {
                            printf("%dx^%d",arr[i],i);
                        }
                        else 
                        {
                            printf("x^%d",i);
                        }
                    }        
                    else if (arr[i]<0)
                    {
                        if (arr[i]!=-1)
                        {
                            printf("%dx^%d",arr[i],i);
                        }
                        else 
                        {
                            printf("-x^%d",i);
                        } 
                        
                    }
                }
            }
        }
    }
    else printf("0");
}

int dem(double n)
{
    if (n<0)
    {
        n=-n;
    }
    n+=0.000009;
    int count=5;
    n=n-(int)n;
    n=n*1000000000;
    int b=((int)n+1)/10000;
    if (b==0)
    {
        return 0;
    }
    while(b % 10==0)
    {
        count--;
        b=b/10;
    }
    return count;
}

void hienthi2(double *arr)
{

    if (check2(arr))
    {
        if (arr[0]!=0)
        {
            int n=dem(arr[0]);
            printf("%.*f",n,arr[0]);
        }

        if (kt_pt_dautien2(arr,1)==0)
        {
            if (arr[1]!=0)
            {
                if (arr[1]>0 )
                {
                    if (arr[1]!=1)
                    {
                        int n=dem(arr[1]);
                        printf("+%.*fx",n,arr[1]);
                    }
                    else 
                    {
                        printf("+x");
                    }
                }
                else if (arr[1]<0)
                {
                    if (arr[1]!=-1)
                    {
                        int n=dem(arr[1]);
                        printf("%.*fx",n,arr[1]);
                    }
                    else 
                    {
                        printf("-x");
                    } 
                }
            }
        }
        else
        {
            if (arr[1]!=0)
            {
                if (arr[1]>0 )
                {
                    if (arr[1]!=1)
                    {
                        int n=dem(arr[1]);
                        printf("%.*fx",n,arr[1]);
                    }
                    else 
                    {
                        printf("x");
                    }
                }
                else if (arr[1]<0)
                {
                    if (arr[1]!=-1)
                    {
                        int n=dem(arr[1]);
                        printf("%.*fx",n,arr[1]);
                    }
                    else 
                    {
                        printf("-x");
                    } 
                }
            }
        }
        
        for (int i=2;i<=max_chia(arr);i++)
        {
            if (kt_pt_dautien2(arr,i)==0)
            {
                if (arr[i]!=0)
                {
                    if (arr[i]>0)
                    {
                        if (arr[i]!=1)
                        {
                            int n=dem(arr[i]);
                            printf("+%.*fx^%d",n,arr[i],i);
                        }
                        else 
                        {
                            printf("+x^%d",i);
                        }
                    }
                    else if (arr[i]<0)
                    {
                        if (arr[i]!=-1)
                        {
                            int n=dem(arr[i]);
                            printf("%.*fx^%d",n,arr[i],i);
                        }
                        else 
                        {
                            printf("-x^%d",i);
                        } 
                    }
                }
            }
            else
            {
                if (arr[i]!=0)
                {
                    if (arr[i]>0)
                    {
                        if (arr[i]!=1)
                        {
                            int n=dem(arr[i]);
                            printf("%.*fx^%d",n,arr[i],i);
                        }
                        else 
                        {
                            printf("x^%d",i);
                        }
                    }
                    else if (arr[i]<0)
                    {
                        if (arr[i]!=-1)
                        {
                            int n=dem(arr[i]);
                            printf("%.*fx^%d",n,arr[i],i);
                        }
                        else 
                        {
                            printf("-x^%d",i);
                        } 
                    }
                }
            }
        }
    }
    else printf("0");
}


