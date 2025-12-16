#include <stdio.h>
#include <string.h>

struct Vehicle {
    int id;
    char owner[20];
    char service[20];
    char status[20];
};
int main(){

struct Vehicle v[20];
int count =0;
int choice;
int i;
int sid;

char services[3][20] =  {"washing", "Oilchange", "Fullservice"};


do {
    printf("\n --Vehicle Service System ---");
    printf("\n1. Add Vehicle");
    printf("\n2. Book Service");
    printf("\n3. Update Status");
    printf("\n4. Delivery Record");
    printf("\n5. Exit");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    //1.Add vehicle
    if(choice ==1){
        printf("Enter Vehicle Id:");
        scanf("%d", &v[count].id);

        printf("Enter Owner Name: ");
        scanf("%s",v[count].owner);

        strcpy(v[count].service, "NotBooked");
        strcpy(v[count].status, "pending");
        
        count++;
        printf("Vehicle Added\n");
    
    }
    //2.Service booking
    else if(choice ==2){
        printf("Enter Vehicle ID: ");
        scanf("%d",&sid);
    for(i =0; i < count; i++){
        if(v[i].id == sid) {
            printf("1 Washing\n2. Oilchang\n3. Fullservice\n");
            printf("Choose Service: ");
            scanf("%d",&choice);

            strcpy(v[i].service, services[choice -1]);
            printf("Sercice Booked\n");
        }
     }
 }
 //3.update status
 else if(choice ==3){
    printf("Enter Vechile ID: ");
    scanf("%d",&sid);

    for(i = 0; i < count; i++){
    if(v[i].id == sid) {
        printf("1. Pending\n2.Completed\n");
        printf("Choose Staus: ");
        scanf("%d", &choice);

        if(choice == 1)
        strcpy(v[i].status,"panding");

        else if(choice == 2)
        strcpy(v[i].status,"Completed");

        printf("Status Update\n");
    }
    }
 }

 //4.Delivery record
    else if(choice == 4){
       printf("\n ---Delivary Record ---\n");
       for(i =0; i < count; i++) {
        if(strcmp(v[i].status,"Completed") == 0) {
            printf("ID:%d Owner:%s Service:%s Status:%s\n",v[i].id, v[i].owner, v[i].service, v[i].status);
        }
       }
    }
}while(choice != 5);


    return 0;
}

void saveToFile(struct Vehicle v) {
    FILE *fp;
    fp = fopen("service_record.txt", "a");
    fprintf(fp, "%d %s %s %s\n",v.id, v.owner, v.service, v.status);
        fclose(fp);
}