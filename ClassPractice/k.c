#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char PASSWORD[] = "SEA520";
static int balance = 20000;

short select_menu() {
    short m;
    printf("\n--- Menu ---\n");
    printf(">>>Balance :%d \n",balance);
    printf("0: Exit\n");
    printf("1: Deposit\n");
    printf("2: Withdraw\n");
    printf("Select menu no. >> ");
    scanf("%hd", &m);
    switch (m) {
        case 0:
            printf("Exiting program...\n");
            exit(0);
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        default:
            printf("Invalid option! Try again.\n");
    }
    return m;
}

void check_password() {
    char pw[50];
    int ch=0, er=3;  //
    while (1) {
        printf("===Enter Password: ");
        scanf("%s", pw);
        ch++;
        er--;
        if (strcmp(pw, PASSWORD) == 0) {
            printf("Login successful o_o\n\n");
            break;  // ออกจาก loop ไปทำเมนู
        } else {
            printf("Wrong password! Try again. #%d in 3 \n",er);
        }if (ch==3){
        printf("!!!Unsafe system!!!");
        exit(0);
        }}}


        void deposit() {
    int amount = get_amount("Amount to deposit >> ");
    update_balance(amount);
}
void withdraw() {
    int amount = get_amount("Amount to withdraw >> ");
    if (amount > balance) {
        printf("-_-Insufficient balance! You have %d -_- \n", balance);
    } else {
        update_balance(-amount);
    }}
int get_amount(char msg[100]) {    //รับ อาร์กิวเมนต์ คือ msg ซึ่งเป็น ข้อความแบบ string
    int amount;
    printf("%s", msg);
    scanf("%d", &amount);
    if (amount >= 0) {
        return amount;
    } else {
        printf("Amount cannot be negative! Try again.\n");
        return get_amount(msg);
    }}
void update_balance(int amount) {
    balance += amount;
    printf("Current balance = %d US\n", balance);
}

__int32_t main()
{
    printf("=== Welcome to Aim Simulator ===\n");
    check_password();
    while(true){
        select_menu();
    }
    return 0;
}