// #include <stdio.h>
// #include <string.h>

// typedef struct Transmitsion{
//     char date[21];
//     char time[9];
//     char name[100];
//     char id[100];
// }trans;

// int main(){
//     trans a[1000];
//     int i = 0;
//     char req[100];
    
//     // Nhập thông tin về trans
//     while(1){
//         scanf("%s", a[i].date);
//         if(strcmp(a[i].date, "*")==0){
//             break;
//         }else{
//             scanf("%s %s %s %s", a[i].date, a[i].time, a[i].name, a[i].id);
//             i++;
//         }
//     }
    
//     // Khởi tạo mảng 2 chiều lưu trữ số lượng trans của mỗi ngày
//     int count[1000][2];
//     int num_dates = 0;
    
//     // Duyệt qua mảng trans và tăng giá trị của phần tử tương ứng trong mảng count tùy theo ngày của từng trans
//     for(int j = 0; j < i; j++){
//         int found = 0;
//         // Kiểm tra xem ngày của trans đã có trong mảng count chưa
//         for(int k = 0; k < num_dates; k++){
//             if(strcmp(count[k][0], a[j].date) == 0){
//                 count[k][1]++;
//                 found = 1;
//                 break;
//             }
//         }
//         // Nếu ngày của trans chưa có trong mảng count thì thêm vào và đặt số lượng trans là 1
//         if(!found){
//             strcpy(count[num_dates][0], a[j].date);
//             count[num_dates][1] = 1;
//             num_dates++;
//         }
//     }
    
//     // In ra số lượng trans của mỗi ngày
//     for(int j = 0; j < num_dates; j++){
//         printf("%s %d\n", count[j][0], count[j][1].count);
//     }
    
//     return 0;
// }
