#include <stdio.h>

#define MAX_PACKAGES 100

int packageCount = 0;
float packageNo[MAX_PACKAGES];
float profit[MAX_PACKAGES];
float itemWeight[MAX_PACKAGES];
float valueRatio[MAX_PACKAGES];
float selectedFraction[MAX_PACKAGES];
float vehicleCapacity = 0;

/* Accept package information from the user */
void enterPackages()
{
    int i;

    printf("Enter number of packages (1-%d): ", MAX_PACKAGES);
    scanf("%d", &packageCount);

    if (packageCount < 1 || packageCount > MAX_PACKAGES)
    {
        printf("Invalid number of packages!\n");
        packageCount = 0;
        return;
    }

    printf("Enter vehicle capacity: ");
    scanf("%f", &vehicleCapacity);

    if (vehicleCapacity <= 0)
    {
        printf("Capacity must be positive!\n");
        packageCount = 0;
        return;
    }

    for (i = 0; i < packageCount; i++)
    {
        packageNo[i] = i + 1;
        selectedFraction[i] = 0;

        printf("\nPackage %d\n", i + 1);

        printf("Enter profit/value: ");
        scanf("%f", &profit[i]);

        printf("Enter weight: ");
        scanf("%f", &itemWeight[i]);

        if (itemWeight[i] <= 0 || profit[i] < 0)
        {
            printf("Invalid value or weight entered!\n");
            packageCount = 0;
            return;
        }

        valueRatio[i] = profit[i] / itemWeight[i];
    }

    printf("\nPackage details entered successfully!\n");
}

/* Display all package information */
void displayPackages()
{
    int i;

    if (packageCount == 0)
    {
        printf("Please enter valid package details first.\n");
        return;
    }

    printf("\nPackage\tValue\tWeight\tRatio\n");

    for (i = 0; i < packageCount; i++)
    {
        printf("%.0f\t%.2f\t%.2f\t%.2f\n",
               packageNo[i], profit[i],
               itemWeight[i], valueRatio[i]);
    }
}

/* Calculate and display value-to-weight ratios */
void showRatios()
{
    int i;

    if (packageCount == 0)
    {
        printf("Please enter package details first.\n");
        return;
    }

    printf("\nValue-to-Weight Ratios:\n");

    for (i = 0; i < packageCount; i++)
    {
        valueRatio[i] = profit[i] / itemWeight[i];

        printf("Package %.0f: %.2f / %.2f = %.2f\n",
               packageNo[i], profit[i],
               itemWeight[i], valueRatio[i]);
    }
}

/* Arrange packages using Selection Sort */
void sortPackages()
{
    int i, j, maxIndex;
    float temp;

    if (packageCount == 0)
    {
        printf("Please enter package details first.\n");
        return;
    }

    for (i = 0; i < packageCount; i++)
        valueRatio[i] = profit[i] / itemWeight[i];

    for (i = 0; i < packageCount - 1; i++)
    {
        maxIndex = i;

        for (j = i + 1; j < packageCount; j++)
        {
            if (valueRatio[j] > valueRatio[maxIndex])
                maxIndex = j;
        }

        if (maxIndex != i)
        {
            temp = valueRatio[i];
            valueRatio[i] = valueRatio[maxIndex];
            valueRatio[maxIndex] = temp;

            temp = profit[i];
            profit[i] = profit[maxIndex];
            profit[maxIndex] = temp;

            temp = itemWeight[i];
            itemWeight[i] = itemWeight[maxIndex];
            itemWeight[maxIndex] = temp;

            temp = packageNo[i];
            packageNo[i] = packageNo[maxIndex];
            packageNo[maxIndex] = temp;
        }
    }

    printf("\nPackages sorted by decreasing ratio.\n");
    displayPackages();
}

/* Apply the Fractional Knapsack Greedy Algorithm */
void findMaximumValue()
{
    int i;
    float remainingCapacity, totalProfit = 0;
    float totalWeight = 0;

    if (packageCount == 0)
    {
        printf("Please enter package details first.\n");
        return;
    }

    /* Calculate ratios and sort before selecting packages */
    sortPackages();

    remainingCapacity = vehicleCapacity;

    for (i = 0; i < packageCount; i++)
        selectedFraction[i] = 0;

    printf("\nPackage Selection Process:\n");

    for (i = 0; i < packageCount; i++)
    {
        if (remainingCapacity <= 0)
            break;

        if (itemWeight[i] <= remainingCapacity)
        {
            selectedFraction[i] = 1.0;
            totalProfit += profit[i];
            totalWeight += itemWeight[i];
            remainingCapacity -= itemWeight[i];
        }
        else
        {
            selectedFraction[i] =
                remainingCapacity / itemWeight[i];

            totalProfit += profit[i] * selectedFraction[i];
            totalWeight += remainingCapacity;
            remainingCapacity = 0;
        }

        printf("Package %.0f: fraction selected = %.2f\n",
               packageNo[i], selectedFraction[i]);
    }

    printf("\nTotal Weight Used = %.2f\n", totalWeight);
    printf("Maximum Value Obtained = %.2f\n", totalProfit);
}

/* Display selected fractions in original package order */
void displaySelection()
{
    int i, j;

    if (packageCount == 0)
    {
        printf("Please enter package details first.\n");
        return;
    }

    printf("\nPackage\tFraction Selected\n");

    for (i = 1; i <= packageCount; i++)
    {
        for (j = 0; j < packageCount; j++)
        {
            if (packageNo[j] == i)
            {
                printf("%.0f\t%.2f\n",
                       packageNo[j], selectedFraction[j]);
                break;
            }
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== FRACTIONAL KNAPSACK =====\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratios\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                enterPackages();
                break;

            case 2:
                displayPackages();
                break;

            case 3:
                showRatios();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelection();
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Select 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}
