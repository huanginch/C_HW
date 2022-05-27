#include <stdio.h>

void initArr(unsigned char status[], int status_len);//init array

/*
* add login times:
* the status array size is one byte, and I save person one at
* the two bits at the right in status[0](I define it as position 0), 
* person two at third and fourth bits in status[0](I define  it as position 1),
* and so on.
* each status[index] can save four people
*/
void add_login(int user_id, unsigned char status[], int status_len); 
int check_status(int user_id, unsigned char status[]);//check user login status, pass return 1 , fail return 0

int main(void){
    int n = 0;//number of users
    scanf("%d", &n);

    int status_len = n/4; //one person use tow bits
    unsigned char status[status_len];
    initArr(status, status_len);

    int user_id = 0;
    int user_status = 0;
    while(scanf("%d",&user_id) != EOF){
        add_login(user_id, status, status_len);
    }
}

void initArr(unsigned char status[], int status_len){
    int i;
    for(i = 0; i < status_len; i++){
        status[i] = 0;
    }
}

void add_login(int user_id, unsigned char status[], int status_len){
    if(check_status(user_id, status) == 0){
        //do not pass
        printf("GOOD BYE\n");
        return;
    }

    //pass and add
    int index = user_id / 4; //index of user_id in status
    int pos = user_id % 4; // position of user_id in status[index];
    int carry = 0;//the carry bit when add one
    if(pos == 0){
        //at position 0
        carry = ( status[index] & 1 ) << 1;
        status[index] = status[index] ^ 1;
    }
    else if(pos == 1){
        //at position 1
        carry = ( status[index] & 4 ) << 1;
        status[index] = status[index] ^ 4;
    }
    else if(pos == 2){
        //at position 2
        carry = ( status[index] & 16 ) << 1;
        status[index] = status[index] ^ 16;
    }
    else if(pos == 3){
        //at position 3
        carry = ( status[index] & 64 ) << 1;
        status[index] = status[index] ^ 64;
    }
    
    status[index] = status[index] ^ carry; //add carry
    // printf("carry: %d, status[index]: %d\n", carry, status[index]);
    printf("PASS\n");
    
}

int check_status(int user_id, unsigned char status[]){
    int index = user_id / 4;
    int pos = user_id % 4;
    unsigned char check_bit = 0;

    if(pos == 0){//at position 0
        check_bit = 3;
    }
    else if(pos == 1){//at position 1
        check_bit = 12;
    }
    else if(pos == 2){//at position 2
        check_bit = 48;
    }
    else if(pos == 3){//at position 3
        check_bit = 192;
    }

    // printf("--------------\n");
    // printf("check res: %d\n", status[index] & check_bit);

    if((status[index] & check_bit) != check_bit){
        //pass
        return 1;
    }
    else{
        //fail
        return 0;
    }
}