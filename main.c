/*
Author: Gilang Ramadhan Ilhami
*/

#include <stdio.h>

struct Person {
    char name[100];
    int age;
    char gender;
    int height;
};

double heightAverage(struct Person *);
int maxHeight(struct Person *);
int minHeight(struct Person *);
double maleAverage(struct Person *);
double femaleAverage(struct Person *);

void heightComparison(struct Person *);

int main()
{
    struct Person person[3];
    char gender;
    int height;
    
    double mean;
    double maleMean;
    double femaleMean;
    int max;
    int min;
    
    for (int i= 0; i <3; i++) {
        
        printf("Enter name: ");
        scanf("%s", &person[i].name);
        
        printf("Enter age: ");
        scanf("%d", &person[i].age);
        
        printf("Enter gender: ");
        scanf("%s", &person[i].gender);
        
        printf("Enter height: ");
        scanf("%d", &person[i].height);
        
        printf("############################################\n");
        printf("The following information has been stored:\n");
        printf("Name: %s\n", person[i].name);
        printf("Age: %d\n", person[i].age);
        printf("Gender: %c\n", person[i].gender);
        printf("Height: %d\n", person[i].height);
        printf("############################################\n");
        
        
    }
    
    mean = heightAverage(person);
    printf("Mean Height: %.2f\n", mean);
    
    max = maxHeight(person);
    printf("Max Height: %d\n", max);
    
    min = minHeight(person);
    printf("Min Height: %d\n", min);
    
    maleMean = maleAverage(person);
    printf("Male Mean Height: %.2f\n", maleMean);
    
    femaleMean = femaleAverage(person);
    printf("Female Mean Height: %.2f\n", femaleMean);
    
    heightComparison(person);

    
    return 0;
}

double heightAverage(struct Person *person){
    double totalHeight;
    int counter;
    double mean;
    
    totalHeight = 0.0;
    counter = 0;
    
    for (int i = 0; i <3; i++) {
        totalHeight += (double)person[i].height;
        counter += 1;
    }
    
    mean = totalHeight/(double)counter;
    return mean;
}

int maxHeight(struct Person *person) {
    int currentMax;
    currentMax = person[0].height;
    
    for (int i = 1; i <3; i++) {
        
        if (person[i].height > currentMax){
            currentMax = person[i].height;
        }
    }
    
    return currentMax;
}

int minHeight(struct Person *person) {
    int currentMin;
    currentMin = person[0].height;
    
    for (int i = 1; i <3; i++) {
        
        if (person[i].height < currentMin){
            currentMin = person[i].height;
        }
    }
    
    return currentMin;
}

double maleAverage(struct Person *person) {
    double totalMaleHeight;
    int counter;
    double mean;
    
    totalMaleHeight = 0.0;
    counter = 0;
    
    
    for (int i = 0; i <3; i++) {
        
        if (person[i].gender == 'm' || person[i].gender == 'M') {
            totalMaleHeight += (double)person[i].height;
            counter +=1;
        }
    }
    
    mean = totalMaleHeight/(double)counter;
    return mean;
}

double femaleAverage(struct Person *person) {
    double totalFemaleHeight;
    int counter;
    double mean;
    
    totalFemaleHeight = 0.0;
    counter = 0;
    
    
    for (int i = 0; i <3; i++) {
        
        if (person[i].gender == 'f' || person[i].gender == 'F') {
            totalFemaleHeight += (double)person[i].height;
            counter +=1;
        }
    }
    
    mean = totalFemaleHeight/(double)counter;
    return mean;
}

void heightComparison(struct Person *person) {
    double femaleHeight = femaleAverage(person);
    double maleHeight = maleAverage(person);
    
    
    if (femaleHeight > maleHeight) {
        printf("Females are taller than Males on average.");
    } else if (femaleHeight < maleHeight) {
        printf("Males are taller than Females on average.");
    } else {
        printf("We are all equal");
    }
    
    return;
}
