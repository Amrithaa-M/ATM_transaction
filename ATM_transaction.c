#include<stdio.h>
#include<stdlib.h>

void withdrawAmt(float *balance){
    int amount;
    up:
        printf("Enter the amount to be withdrawn: ");
        scanf("%d", &amount);
        
        if(amount>*balance){
            printf("\nINSUFFICIENT BALANCE\n");
            printf("Your current bank balance: %.2f\n", *balance);
        }
        
        else if(amount>200000){
            printf("Amount exceeds the limitation.\nPlease enter again.\n");
            goto up;
        }
        
        else if(amount<0){
            printf("INVALID INPUT. Try again\n");
            goto up;
        }
        
        else{
            if(amount%100==0){
                *balance-=amount;
                printf("Successfully withdrawn!\n");
                printf("Current Balance: %.2f\n", *balance);
                printf("\n");
            }
            else{
                printf("Enter value in terms of 100\n\n");
                goto up;
            }
        }
}

void depositAmt(float *balance){
    int amount;
    up:
        printf("Enter the amount to be deposited: ");
        scanf("%d", &amount);
        
        if(amount>200000){
            printf("Amount exceeds the limitation.\nPlease enter again.\n");
            goto up;
        }
        
        else{
            if(amount%100==0){
                *balance+=amount;
                printf("Successfully deposited!\n");
                printf("Current Balance: %.2f\n", *balance);
                printf("\n");
            }
            
            else{
                printf("Enter value in terms of 100\n\n");
                goto up;
            }
        }
}

void fastCash(float *balance){
    int choice;
    
    printf("\nSelect an amount:\n\n");
    printf("1. ₹100                                      4. ₹2500\n");
    printf("2. ₹500                                      5. ₹5000\n");
    printf("3. ₹1000                                     6. ₹10000\n\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: if(*balance<100)
                    printf("INSUFFICIENTBALANCE\n");
                else{
                    *balance-=100;
                    printf("Successfully withdrawn!\n");
                }
                break;
                
        case 2: if(*balance<500)
                    printf("INSUFFICIENTBALANCE\n");
                else{
                    *balance-=500;
                    printf("Successfully withdrawn!\n");
                }
                break;
                
        case 3: if(*balance<1000)
                    printf("INSUFFICIENTBALANCE\n");
                else{
                    *balance-=1000;
                    printf("Successfully withdrawn!\n");
                }
                break;
                
        case 4: if(*balance<2500)
                    printf("INSUFFICIENTBALANCE\n");
                else{
                    *balance-=2500;
                    printf("Successfully withdrawn!\n");
                }
                break;
                
        case 5: if(*balance<5000)
                    printf("INSUFFICIENTBALANCE\n");
                else{
                    *balance-=5000;
                    printf("Successfully withdrawn!\n");
                }
                break;
                
        case 6: if(*balance<10000)
                    printf("INSUFFICIENTBALANCE\n");
                else{
                    *balance-=10000;
                    printf("Successfully withdrawn!\n");
                }
                break;
                
        default: printf("INVALID CHOICE");
    }
}

int main(){
    float balance = 10000;
    int choice, pinCode;
    
    printf("(Your pincode: 1234)\n");
    
    above:
    
    printf("\nEnter your pincode: ");
    scanf("%d", &pinCode);
    
    if(pinCode==1234){
        
        printf("\n--------------WELCOME--------------\n\n");
        printf("1. Fast Cash\n");
        printf("2. Balance Inquiry\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Quit\n");
        printf("\n-----------------------------------\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            
            case 1: fastCash(&balance);
                    break;
                    
            case 2: printf("Your current bank balance: %.2f\n", balance);
                    break;
                    
            case 3: depositAmt(&balance);
                    break;
                    
            case 4: withdrawAmt(&balance);
                    break;
                    
            case 5: exit(0);
            
            default: printf("INVALID CHOICE\n");
        }
    }
    
    else{
        printf("INVALID PIN CODE\n");
        goto down;
    }
    
    printf("\nWould you like to make another transaction?[1/0]\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    
    if(choice==1)
        goto above;
    else
        down:
        printf("\nThank you for your visit!\n");
        
    return 0;
}