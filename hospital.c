#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient
{
    int id;
    char name[50];
    int age;
    int priority;
    struct patient *next;
};

struct patient *head = NULL;



char* get_priority_name(int priority)
{
    if(priority == 1) return "Emergency";
    if(priority == 2) return "Critical";
    if(priority == 3) return "Normal";
    if(priority == 4) return "General";
    return "Unknown";
}



struct patient* create_patient(int id, char name[], int age, int priority)
{
    struct patient *newnode;

    newnode = (struct patient*)malloc(sizeof(struct patient));

    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->age = age;
    newnode->priority = priority;
    newnode->next = NULL;

    return newnode;
}



void insert_patient(int id, char name[], int age, int priority)
{
    struct patient *newnode;
    struct patient *temp;

    temp = head;
    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("Error: Patient ID already exists\n");
            return;
        }
        temp = temp->next;
    }

    newnode = create_patient(id, name, age, priority);

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    if(priority < head->priority)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        if(temp->next->priority > priority)
        {
            break;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}



void display()
{
    struct patient *temp;

    if(head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head;

    printf("\nID   Name   Age   Priority\n");
    printf("---------------------------------\n");

    while(temp != NULL)
    {
        printf("%d   %s   %d   %s\n",
               temp->id,
               temp->name,
               temp->age,
               get_priority_name(temp->priority));

        temp = temp->next;
    }
}



void treat_patient()
{
    struct patient *temp;

    if(head == NULL)
    {
        printf("No patient available\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First patient treated\n");
}



void delete_by_id(int id)
{
    struct patient *temp;
    struct patient *previous;

    if(head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head;
    previous = NULL;

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            break;
        }
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Patient not found\n");
        return;
    }

    if(previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    free(temp);

    printf("Patient deleted\n");
}



void search_patient(int id)
{
    struct patient *temp;

    temp = head;

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("Found Patient\n");
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Priority: %s\n",
                   get_priority_name(temp->priority));
            return;
        }

        temp = temp->next;
    }

    printf("Patient not found\n");
}



void update_patient(int id)
{
    struct patient *temp;
    char new_name[50];
    int new_age;
    int new_priority;

    if(head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("Enter new Name: ");
            scanf(" %[^\n]", new_name);

            printf("Enter new Age: ");
            scanf("%d", &new_age);

            while(1)
            {
                printf("Select new Priority\n");
                printf("1 Emergency\n");
                printf("2 Critical\n");
                printf("3 Normal\n");
                printf("4 General\n");

                scanf("%d", &new_priority);

                if(new_priority >= 1 && new_priority <= 4)
                {
                    break;
                }
                
                printf("Invalid priority! Please enter 1-4\n");
            }

            /* 
             * Instead of modifying the node and then re-sorting the whole list,
             * it's safer and cleaner to delete the old node and insert a new one
             * to maintain the priority queue order.
             */
            delete_by_id(id);
            insert_patient(id, new_name, new_age, new_priority);
            
            printf("Patient updated successfully\n");
            return;
        }

        temp = temp->next;
    }

    printf("Patient not found\n");
}



void reverse_list()
{
    struct patient *previous;
    struct patient *current;
    struct patient *nextnode;

    previous = NULL;
    current = head;

    while(current != NULL)
    {
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }

    head = previous;

    printf("Queue reversed\n");
}



void find_middle()
{
    struct patient *slow;
    struct patient *fast;

    if(head == NULL)
    {
        printf("Queue empty\n");
        return;
    }

    slow = head;
    fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Patient: %s (ID %d)\n",
           slow->name,
           slow->id);
}



void show_statistics()
{
    struct patient *temp;
    int total = 0;
    int emergency_count = 0;
    int critical_count = 0;
    int normal_count = 0;
    int general_count = 0;

    temp = head;

    while(temp != NULL)
    {
        total = total + 1;

        if(temp->priority == 1)
        {
            emergency_count = emergency_count + 1;
        }
        else if(temp->priority == 2)
        {
            critical_count = critical_count + 1;
        }
        else if(temp->priority == 3)
        {
            normal_count = normal_count + 1;
        }
        else if(temp->priority == 4)
        {
            general_count = general_count + 1;
        }

        temp = temp->next;
    }

    printf("Total Patients: %d\n", total);
    printf("Emergency Patients: %d\n", emergency_count);
    printf("Critical Patients: %d\n", critical_count);
    printf("Normal Patients: %d\n", normal_count);
    printf("General Patients: %d\n", general_count);
}



void save_to_file()
{
    FILE *fp;
    struct patient *temp;

    fp = fopen("patients.txt", "w");
    if(fp == NULL)
    {
        printf("Error: Could not save file\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%d %s %d %d\n",
                temp->id,
                temp->name,
                temp->age,
                temp->priority);

        temp = temp->next;
    }

    fclose(fp);
}



void load_from_file()
{
    FILE *fp;
    int id;
    int age;
    int priority;
    char name[50];

    fp = fopen("patients.txt", "r");

    if(fp == NULL)
    {
        return;
    }

    while(fscanf(fp, "%d %s %d %d",
                 &id, name, &age, &priority) == 4)
    {
        insert_patient(id, name, age, priority);
    }

    fclose(fp);
}



int main()
{
    int choice;
    int id;
    int age;
    int priority;
    char name[50];

    load_from_file();

    while(1)
    {
        printf("\n1 Insert Patient\n");
        printf("2 Display Queue\n");
        printf("3 Treat First Patient\n");
        printf("4 Delete By ID\n");
        printf("5 Search Patient\n");
        printf("6 Reverse Queue\n");
        printf("7 Find Middle\n");
        printf("8 Show Statistics\n");
        printf("9 Save and Exit\n");
        printf("10 Update Patient\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter ID: ");
            scanf("%d", &id);

            printf("Enter Name: ");
            scanf(" %[^\n]", name);

            printf("Enter Age: ");
            scanf("%d", &age);

            while(1)
            {
                printf("Select Priority\n");
                printf("1 Emergency\n");
                printf("2 Critical\n");
                printf("3 Normal\n");
                printf("4 General\n");

                scanf("%d", &priority);

                if(priority >= 1 && priority <= 4)
                {
                    break;
                }
                
                printf("Invalid priority! Please enter 1-4\n");
            }

            insert_patient(id, name, age, priority);
        }
        else if(choice == 2)
        {
            display();
        }
        else if(choice == 3)
        {
            treat_patient();
        }
        else if(choice == 4)
        {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            delete_by_id(id);
        }
        else if(choice == 5)
        {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            search_patient(id);
        }
        else if(choice == 6)
        {
            reverse_list();
        }
        else if(choice == 7)
        {
            find_middle();
        }
        else if(choice == 8)
        {
            show_statistics();
        }
        else if(choice == 9)
        {
            save_to_file();
            exit(0);
        }
        else if(choice == 10)
        {
            printf("Enter ID to update: ");
            scanf("%d", &id);
            update_patient(id);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}