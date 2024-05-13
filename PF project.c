#include <stdio.h>
// function for deposit
int deposit(int *deposit_amount, int *total_amount)
{
    int choice;

    printf("Select Any Option \n1: Enter Deposit Amount\n");
    printf("2: Cancel Transaction\n");

    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter Amount:$");

        scanf("%d", deposit_amount);// check for amount greater than zero 
        if (*deposit_amount >= 0)
        {
            *total_amount += *deposit_amount;
            printf("You have Deposited $%d Amount\nYour Total Amount is $%d\n", *deposit_amount, *total_amount);

            return 0;
        }
        else if (*deposit_amount < 0)
        {

            printf("! YOU HAVE ENETERED INVALID AMOUNT !\n");
            deposit_amount = 0;
        }

      // check for cancel transaction
        if (choice == 2)
        {
            return 0;
        }
    }
}

   // function for selecting the process 
int withdrawn(int *withdrawn_amount, int *total_amount)
{   
    int choice;

    printf("Select Any Option \n1: Enter Withdraw Amount\n");
    printf("2: Cancel Transaction\n");

    scanf("%d", &choice);
    if (choice == 1)
    {    
    printf("ENTER AMOUNT TO WITHDRAW:$");
    scanf("%d", withdrawn_amount);
    
    // check for checking the the balance is not less than withdrawl 
    if (*withdrawn_amount > *total_amount)
    {
        printf(" !Insufficient Balance!\n");
    }
    else if(*withdrawn_amount==0||*withdrawn_amount<0){
        printf("! YOU HAVE ENTERED INVALID AMOUNT !\n");

    }
    else
    {
        *total_amount -= *withdrawn_amount;
        printf(" Withdrawn Amount %d$\n Total Amount Remaining %d$\n", *withdrawn_amount, *total_amount);
    }
    }
    else if(choice==2){
        return 0;
    }
}
  
    // function to for pin of the atm 
int pinverify(char pin[],char pinverification[]){
int count;
    do
    {
         
         
        printf("ENTER YOUR PIN :");
        scanf("%s",pinverification);
        for (int i = 0; i < 4; i++)
        {
            if (pin[i] == pinverification[i])
            {
                
                count += 1;
            }
        
            
        }
        
        // check pin validity 
        if(count!=4){
        printf("! YOU HAVE ENTERED INVALID PIN !\n");
        printf("PLEASE ENTER VALID PASSWORD\n");
        count = 0;
        }
    
    } while (count != 4);

        return 0;
}

   // main function
int main()
{
    int total_amount = 0, deposit_amount = 0, withdraw_amount = 0, menu;
    char pin[5] = {'1', '2', '3', '4'};
    char pinverification[5];
    pinverify(pin,pinverification);
     printf("Welcome to ATM Service\n");

    while (menu != 4)
    {
       
        printf("\nSelect Any Option \n \n");
        printf("1: Deposit Amount \n");
        printf("2: Shows Balance \n");
        printf("3: Withdraw\n");
        printf("4: Cancel Transaction\n");



        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            deposit(&deposit_amount, &total_amount);
            break;

        case 2:
            printf("Total Amount in your Account $%d\n", total_amount);

            break;

        case 3:
            withdrawn(&withdraw_amount, &total_amount);
            break;
        
        
        }
    }
    return 0;
}