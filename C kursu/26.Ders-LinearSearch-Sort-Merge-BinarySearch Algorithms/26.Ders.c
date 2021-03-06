#include<stdio.h>
#include "nutility.h"
#include<stdlib.h>
#include<time.h>


//                                                              ARAMA ALGORİTMALARI(LİNEAR SEARCH)
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//              ÖRNEK           -           1           -       dizi içindeki uniq değerleri orjinal dizideki sırasıyla basma
/*
#define SIZE 20
int main()
{
    int a[SIZE];

    randomize();
    for(int i = 0; i < SIZE ; ++i ){
        a[i] = rand() % 20;
        printf("%3d ", a[i]);

    }
    printf("\n\n");


    int i, k;

    for (i = 0; i < SIZE; ++i){
        for ( k = 0; k < SIZE ; ++k){
            if(i != k && a[i]==a[k])
                break;
        }
        if (k == SIZE)
            printf("%3d ", a[i]);// eğer uniq değil ise sıze değerine ulaşamadan break ile çıkacak ama uniq ise size değerine ulaşmadan döngü bitemez
    }

}
*/




//              ÖRNEK           -           2          -       ilk örneği o(n) ile sırasız bir şekilde bulma
/*
#define SIZE 20
int main()
{
    int a[SIZE];
    int cnt[20] = { 0 };// hangi değerden kaç tane var elde tutmak için oluşturduğumuz dizi

    randomize();
    for(int i = 0; i < SIZE ; ++i ){
        a[i] = rand() % 20;
        printf("%3d ", a[i]);

    }
    printf("\n\n");

    for (int i = 0; i < SIZE; ++i){
        ++cnt[a[i]];
    }
    
    for (int i = 0 ; i < 20 ; ++i){
        if (cnt[i] == 1)
            printf("%3d ",   i);
    }

    printf("\n");

}
*/



//              ÖRNEK           -           3(ödev)           -    max subsequence problem    - dizi içindeki küçük dizilerin oluşturduğu subsuqenclerın toplamının en büyük olanını bulma
// subsequence: bir dizi içindeki ardışık sayıların oluşturduğu küçük diziler. Bir elemanı en az negatif olmalı. Bunların toplamları oluyor.
// bu algoritmanın bu kadar ünlü olmasının nedeni "O(n) karmaşılığında çözülenbiliyor" olması. 
/*


#define SIZE 200

int main()
{
    int a[SIZE]={2572, -3310, -2264, -4110, -1239,  432,  -30, 4946, -1818, 1515, 
-1234, -2543, 3498, 3617, 2722, -1040, 1807, 1901, 1344, 1196, 
2275, -2265, 2121, 1757, -3111, 1985, 1671, -4298, -4822, -1070, 
 639, -1174, 4472, 3868, -3084, 1318, 2337, -2004, -3258, 4695, 
3279, 3018, -4796, -1910, -4903,  424, -1310, 3998, -1049, -4378, 
4843, -853, 1439, 1088, -1889, -279, 3370, -3911, -1728, -4074, 
-2942, -3096, -2791, -4736, 2617, 4087, -3735, 3049,  199, -3142, 
1838,  206, 3961,  520, 2805, -1358, 1505,  990, -3514, -1021, 
-2551, -749, 3319, -793, -4832, 3885, 4449, -1347, -3994, 4188, 
2042, -1204, 4921, -2569, 1663, 3429, -2597, 2601, 3603, -4381, 
1617, -1758,  282, 4143, -3014, 2283, 3207, -4530, 1422, 2322, 
-175, 3871, -4562, 3374, 1579, 1518, -2436, -1761, -810, -2514, 
 629,  966, -3748,  824, -4305, -224, 2360, -4436, -1390, -3890, 
 687, 1780, 4232, 2149, 2255, -4483, 4280, 1885, 3097, -2519, 
-1928, 2812, 1819, -4619, -2785, 4925, -815, 4918, 4549, -2202, 
 -58,  482, -4773, 1015, 4366, 1150, -3253, -2109, 3065, -3557, 
4587, -3816, 1603,  325, 1531, 4993,  572, 1120, -214, -2053, 
-3188, -3966, -2838, 4468, 2592, -2257, -468, 1691, -3604, 2032, 
-1154, -4082, -435, 3341, 4305,  254, -569, 2319, 3077, -3960, 
-1114, -2440, -1932,  165, -4352, -1480, 4458, -1820, 3897, -4800, }; 


    
    randomize();

    for ( int i = 0 ; i<SIZE ; ++i ){
        if ( i && i % 10 == 0 )
            printf("\n");
        if( rand() % 2 )
            printf("%4d, ", rand() % 5000);
        else
            printf("%4d, ", -rand() % 5000);
    }
    
}
*/



//              ÖRNEK           -           4                  -    dizinin elemanlarının her biri kadar alt alta yıldız basılacak(örneğin ilk eleman 4 elemanlı ise ilk satır 4 yıldız.)
//kolay versiyon
/*
#define SIZE 20

int main()
{
    int a[SIZE];

    randomize();

    for( int i = 0 ; i < SIZE ; ++i ){
        a[i] = rand() % 20 + 1;
        //printf("%3d ",a[i]);
        }
    for( int i = 0 ; i < SIZE ; ++i ){
        for( int k = 0 ; k < a[i] ; ++k ){
            printf("*");
        }
        printf(" %d",a[i]);
        printf("\n");
    }
}
*/



//              ÖRNEK           -           5 (örnek 4 zor vers)    -    yıldızları satır yerine kolon şeklinde basma ilk eleman 5 elemanlıysa alt alta 5 yıldız olacak sonraki eleman için yan kolona geçilecek.
/*
#define SIZE 5

int main()
{
    int a[SIZE];

    randomize();

    for( int i = 0 ; i < SIZE ; ++i ){
        a[i] = rand() % 20 + 1;
        printf("%3d ",a[i]);    
        }

    int max_a= 0;

    for (int i = 0 ; i < SIZE ; ++i){
        if(a[i] > max_a)
            max_a= a[i];
        if ( (SIZE - 1)  == i)
            break;
    }
    
    int row = max_a;
    for (row; 0 < row; --row){
        printf("\n");
        for ( int i = 0; i < SIZE; ++i){
            if ( row - a[i] <= 0   ){
                printf("*");
            }

            else if (a[i] == 0  ){
                continue;
            }
            else
                printf(" ");
        }
   
    }

}
*/



//                                                               SIRALAMA ALGORİTMALARI(SORT ALGORITHMS)
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//              ÖRNEK           -              6                   -               bubble sort algoritması
/*
#define SIZE 10
int main()
{
    int a[SIZE];

    randomize();

    set_array_random(a, SIZE);
    print_array(a, SIZE);
    printf("\n");
     
    for( int i = 0 ; i < SIZE - 1 ; ++i ){
        for ( int k = 0 ; k < SIZE - 1 - i ; ++k ){
            if( a[k] > a[k + 1] ){//büyükten küçüğe veya küçükten büyüğe sıralama için burayı düzeltme yeterli
                int temp = a[k];
                a[k] = a[k+1];
                a[k+1] = temp; 
            }
        }
    }
    print_array(a, SIZE);

}
*/




//              ÖRNEK           -              7                   -               bubble sort algoritması -  küçükten büyüğe sıralama ve çift tek kendi arasında gruplama
/*
#define SIZE 10
int main()
{
    int a[SIZE];

    randomize();

    set_array_random(a, SIZE);
    print_array(a, SIZE);
    printf("\n");
     
    for( int i = 0 ; i < SIZE - 1 ; ++i ){
        for ( int k = 0 ; k < SIZE - 1 - i ; ++k ){
            if( ( a[k] % 2 == 0 && a[k+1] % 2 != 0 ) || ( a[k] % 2 == a[k+1] % 2 &&  a[k] > a[k+1] ) ){//a[k] çift a[k+1] tek ise değiştir. İkisi de çift/tek ise büyük olanı sağa al dedik kısaca
                int temp = a[k];
                a[k] = a[k+1];
                a[k+1] = temp; 
            }
        }
        print_array(a, SIZE);
    }
}
*/



//              ÖRNEK           -              8        v1           -               quick sort(o(nlogn)) ile bubble sort(o(n^2)) kıyaslaması için süre hesaplama - quick
/*
#define     SIZE    100000
int main()
{   
    int *p = (int *)malloc(SIZE * sizeof(int));

    if(!p) {
        printf("bellek yetersiz\n");
        return 1;
    }
    //bubble sort başlangıç
    set_array_random(p, SIZE);
    //print_array(p, SIZE);
    clock_t start = clock();
    for (int i= 0 ; i < SIZE - 1; ++i){
        for (int k= 0 ; k < SIZE - 1 - i; ++k){
            if ( p[k] > p[k+1] ){
                int temp = p[k];
                p[k] = p[k+1];
                p[k+1] = temp;
            }
    
        }
    
    }
    clock_t end = clock();
    printf("bubble sort siralama tamamlandi toplam sure %f saniye\n",(double)(end-start)/ CLOCKS_PER_SEC);//bubble sort süresini hesaplama . 100BİN lik dizi için 18 saniye
    getchar();
    print_array(p, SIZE);
    free(p); 
}
*/


//              ÖRNEK           -              8        v2           -               quick sort(o(nlogn)) ile bubble sort(o(n^2)) kıyaslaması için süre hesaplama - bubble
/*
#define     SIZE    100000
int icmp(const void* vp1, const void* vp2)
{
    return *(const int*)vp1 - *(const int*)vp2;
}


int main()
{   
    int *p = (int *)malloc(SIZE * sizeof(int));

    if(!p) {
        printf("bellek yetersiz\n");
        return 1;
    }
    set_array_random(p, SIZE);
    //print_array(p, SIZE);
    clock_t start = clock();
    qsort(p, SIZE, sizeof(int), &icmp);//standart c fonksiyonudur.
    clock_t end = clock();
    printf("bubble sort siralama tamamlandi toplam sure %f saniye\n",(double)(end-start)/ CLOCKS_PER_SEC);//quick sort süresini hesaplama . 100BİN lik dizi için 0.0116 saniye
    printf("------------");
    //print_array(p, SIZE);
    free(p); 
}
*/







//                                                              MERGE ALGORİTMASI
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//              ÖRNEK           -               9                    -          merge algoritması ile iki diziyi birleştirme
/*
#define     SIZE        20
int main()
{
    int a[SIZE];
    int b[SIZE];
    int c[SIZE *  2];

    randomize();
    set_array_random(a, SIZE);
    set_array_random(b, SIZE);

    sort_array(a, SIZE);
    sort_array(b, SIZE);
    print_array(a, SIZE);
    print_array(b, SIZE);

    // 3. BİR ARRAY VERİLİYOR. Bu dizi 2 dizinin birleşimi olacak ve  küçükten büyüğe sıralanacak - bu merge algorithms ezberlenmeli
    int idx_a= 0;
    int idx_b= 0;
    for( int i = 0; i < SIZE * 2 ; ++i){
        if      (idx_a == SIZE )// iki diziden biri max eleman sayısına ulaşırsa diğer dizinin elemanına bakılır. Zaten 2*SIZE kadar işlem yapacağı için 2. dizinin maksimumunda otomatik döngü biter.
            c[i] = b[idx_b++];

        else if ( idx_b == SIZE )
            c[i] = a[idx_a++];

        else if  ( a[idx_a] < b[idx_b]) // ilk başta a ve b dizinin ilk elemanları değerleri karşılaştırılır. b büyükse a nın 2. elemanına geçilir
            c[i] = a[idx_a++];

        else
            c[i] = b[idx_b++]; // b nin elemanı daha küçükse b'nin ikinci değerine veya diğer elemanlarına geçilir
    }
    
    print_array(c, SIZE * 2);
}
*/







//                                                              BINARY SEARCH ALGORITHM
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//                          ÖRNEK       -               10          -           Binary search örnek
/*
#define     SIZE        200
int main()
{
    int a[SIZE];
    int sval;

    randomize();
    set_array_random(a, SIZE);
    sort_array(a, SIZE);
    print_array(a, SIZE);

    printf("aranacak degeri girin: ");
    scanf("%d",&sval);

    int idx_first = 0;
    int idx_last  = SIZE - 1;
    int idx_mid;
    int cnt = 0;

    while (idx_first <= idx_last){
        ++cnt;
        idx_mid = (idx_first + idx_last) / 2;

        if( a[idx_mid] == sval )
            break;

        if ( sval > a[idx_mid] ){
            idx_first = idx_mid + 1;
        }

        else if( a[idx_mid] > sval){
            idx_last = idx_mid - 1;
        }

    }

    if(idx_first > idx_last){
        printf("aranan deger bulunamadi\n  %d kadar islem yapildi",cnt);//dizinin boyutunu 2 katına çıkarıp olmayan değeri arattığımızda işlem sayısının sadece 1 arttığı görülüyor. 100 elemanda 7 işlem yapılırken, 200 elemanda 8 işlem yapılıyor.
    }
    else{
        printf("bulundu, dizinin %d indisli elemani\n %d kadar islem yapildi",idx_mid,cnt);
    }

}
*/



//                          ÖRNEK       -               11          -           iki array'in elemanlarının tamamının eşitliğini kontrol etme       
/*
#define     SIZE    5

int main()
{
    int a[SIZE]= {2,5,1,3,4};
    int b[SIZE]= {4,1,2,11,3}; 

    

    //ilave bir dizi kullanarak veya kullanmayarak yapılabilir.
    


}
*/