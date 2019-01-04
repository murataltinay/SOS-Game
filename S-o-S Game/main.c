#include <stdio.h>
#include <stdlib.h>
//MURAT ALTINAY
struct oyuncu
{
    char isim[10];
    int puan;

};
int main()
{
    int oyuncusayisi,i,j,k,q=0;
    int sutun,satir;
    int boyut;
    printf("Matris Oyun Tahtasinin Boyutunu Giriniz (MxM) M=? :");
    scanf("%d",&boyut);
    char matris[boyut][boyut];
    int y;


    printf("Oyuncu sayisini giriniz:");
    scanf("%d",&oyuncusayisi);
    struct oyuncu oyuncular[oyuncusayisi];


    for(i=0; i<oyuncusayisi; i++)
    {
        printf("%d. oyuncunun ismini giriniz:",i+1);
        scanf("%s",oyuncular[i].isim);
        oyuncular[i].puan=0;
    }


    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            matris[i][j]=' ';
        }

    }


    printf("\n");

    for(i=0; i<boyut; i++)
    {
        printf("\t");
        for(j=0; j<boyut; j++)
        {
            printf("[%c]",matris[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");


    for(k=0; k<boyut*boyut; k++)
    {

        if(q==(oyuncusayisi))
        {
            q=0;
        }


Loop:
        printf("%s S icin 1'i, O icin 0 secsin :",oyuncular[q].isim);
        scanf("%d",&y);

        if(!(y==1||y==0))
        {
            printf("Lutfen yalnizca 1 veya 0 girin!\n");

            goto Loop;

        }
Loop1:
        printf("Hangi satirda olsun ve hangi sutunda olsun:");
        scanf("%d %d",&satir,&sutun);


        printf("%d\n",y);
        
        
          if(!(0<=satir<boyut)||!(0<=sutun<boyut))
        {
            printf("Lutfen 0-%d araliginda satir ve sutun secin \n",boyut);

            goto Loop1;
        }


        if(matris[satir][sutun]!=' ')
        {
            printf("Lutfen bos olan bir kutuyu secin!! \n");

            goto Loop1;

        }

      

        if(y==1)
        {
            matris[satir][sutun]='s';
        }
        else
        {
            matris[satir][sutun]='o';
        }

         if((matris[satir][sutun]=='o')&&(matris[satir][sutun-1]=='s')&&(matris[satir][sutun+1]=='s'))
        {
            oyuncular[q].puan++;
        }
        if((matris[satir][sutun]=='o')&&(matris[satir-1][sutun]=='s')&&(matris[satir+1][sutun]=='s')){
        	oyuncular[q].puan++;
		}
        if((matris[satir][sutun]=='o')&&(matris[satir-1][sutun-1]=='s')&&(matris[satir+1][sutun+1]=='s')){
        	oyuncular[q].puan++;
		}
        if((matris[satir][sutun]=='s')&&(matris[satir][sutun+1]=='o')&&(matris[satir][sutun+2]=='s')){
            oyuncular[q].puan++;
        }
        
        if((matris[satir][sutun]=='s')&&(matris[satir][sutun-1]=='o')&&(matris[satir][sutun-2]=='s')){
            oyuncular[q].puan++;
        }
        
        if((matris[satir][sutun]=='s')&&(matris[satir-1][sutun]=='o')&&(matris[satir-2][sutun]=='s')){
            oyuncular[q].puan++;
        }
        
        if((matris[satir][sutun]=='s')&&(matris[satir+1][sutun]=='o')&&(matris[satir+2][sutun]=='s')){
            oyuncular[q].puan++;
        }
        
       if((matris[satir][sutun]=='s')&&(matris[satir-1][sutun-1]=='o')&&(matris[satir-2][sutun-2]=='s')) {
            oyuncular[q].puan++;
        }
        
       if((matris[satir][sutun]=='s')&&(matris[satir][sutun+1]=='o')&&(matris[satir][sutun+2]=='s')) {
            oyuncular[q].puan++;
        }        
//MURAT ALTINAY

        for(i=0; i<boyut; i++)
        {
            printf("\t");
            for(j=0; j<boyut; j++)
            {
                printf("[%c]",matris[i][j]);
            }
            printf("\n");
        }

        q++;
    }
    printf("--------------------------------------------------------\n");
    printf("\t\t---------OYUN BITTI----------\n");
    printf("Puanlar :\n");
    for(i=0; i<oyuncusayisi; i++)
    {
        printf("%s: %d\n",oyuncular[i].isim,oyuncular[i].puan);
    }
    int enbuyuk=oyuncular[0].puan;
    int index=0;
    for(i=1; i<oyuncusayisi; i++)
    {
        if(oyuncular[i].puan>enbuyuk)
        {
            enbuyuk=oyuncular[i].puan;
            index=i;
        }
    }		
    	int enbuyuksayisi=0;
      for(i=1; i<oyuncusayisi; i++)
    {
        if(oyuncular[i].puan=enbuyuk)
        {
            enbuyuksayisi++;
        }
    }
    
    if(enbuyuksayisi==0&&enbuyuk==0){
    printf("--------------------------------------------------------\n\n");
    printf("\t\tKAZANAN YOK! Kimse Puan KAZANAMADI !" );
    printf("\n\n--------------------------------------------------------");
	}
	else if(enbuyuksayisi==1){
	printf("--------------------------------------------------------\n\n");
    printf("\t\tKAZANAN :%d puanla %s ! ",oyuncular[index].puan,oyuncular[index].isim);
    printf("\n\n--------------------------------------------------------");		
	}
	else{
		 for(i=1; i<oyuncusayisi; i++)
    {
        if(oyuncular[i].puan=enbuyuk)
        {
    printf("--------------------------------------------------------\n\n");
    printf("\t\tKAZANAN :%d puanla %s ! ",oyuncular[i].puan,oyuncular[i].isim);
    printf("\n\n--------------------------------------------------------");	
        }
        printf("\n Esitlik Var! \n");
    }
				
	}
    
    
    
    printf("--------------------------------------------------------\n\n");
    printf("\t\tKAZANAN :%d puanla %s ! ",oyuncular[index].puan,oyuncular[index].isim);
    printf("\n\n--------------------------------------------------------");
    return 0;
}
