#include <iostream>

int upper_bound(int *first, int *last, int n){
    int *e = first;
    int *d = last;

    while(e < d){
        int *m = e + (d - e)/2;

        if(*m <= n){
            e = m + 1;
        }else{
            d = m;
        }
    }

    return std::distance(first, e-1);
}

int lower_bound(int *first, int *last, int n){
    int *e = first;
    int *d = last;

    while(e < d){
        int *m = e + (d - e)/2;

        if(*m < n){
            e = m + 1;
        }else{
            d = m;
        }
    }

    return std::distance(first, e);
}

// int lower_bound(int *first, int *last, int n){
//     int *e = first;
//     int *d = last-1;

//     while(e <= d){
//         int *m = e + (d - e) / 2;

//         if(*m == n){
//             // return std::distance(first, m);
//             d = m;
//             while(true){
//                 m = e + (d - e) / 2;

//                 // std::cout << "e: " << *e << "\n";
//                 // std::cout << "d: " << *d << "\n";
//                 // std::cout << "m: " << *m << "\n";

//                 if(e == d){
//                     return std::distance(first, m);
//                 }
//                 if(*m == *d){
//                     d = m;
//                 }else{
//                     e = m + 1;
//                 }
//             }
//         }
//         if(n < *m){
//             d = m - 1;
//         }else{
//             e = m + 1;
//         } 
//     }
    
//     return -1;
// }

int binary_search(int *first, int *last, int n){
    int *e = first;
    int *d = last-1;

    while(e <= d){
        int *m = e + (d - e) / 2;

        if(*m == n){
            return std::distance(first, m);
        }
        if(n < *m){
            d = m - 1;
        }else{
            e = m + 1;
        } 
    }
    
    return -1;
}

int main(){

    int v[] = {1, 2, 3, 4, 5, 6};
    int v2[] = {1, 1, 1, 1, 1, 2};

    // std::cout << "Posicao: " << binary_search(v, v+6, 6) << "\n";

    std::cout << "Posicao: " << lower_bound(v2, v2+6, 2) << "\n";

    // std::cout << "Posicao: " << upper_bound(v2, v2+6, 2) << "\n";
    

    return 0;
}