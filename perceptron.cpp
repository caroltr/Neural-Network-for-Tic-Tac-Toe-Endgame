#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int signal(double x)
{
    return ( x >= 0 ? +1 : -1);
}

int main()
{
    int x[1000][19], d[1000], y[1000];
    double w[19];

    // 1. read data from file
    int ix = 0;
    while
    (
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        &x[ix][0], &x[ix][1],  &x[ix][2],  &x[ix][3],  &x[ix][4],  &x[ix][5],  &x[ix][6],  &x[ix][7],  &x[ix][8],  &x[ix][9], &x[ix][10], &x[ix][11], &x[ix][12], &x[ix][13], &x[ix][14], &x[ix][15], &x[ix][16], &x[ix][17], &x[ix][18], &d[ix]) != EOF
    )
    { ix++; }

    // 2. initialize synaptic weights
    srand(time(NULL));
    for (int i=0; i<19; i++)
        w[i] = (double)((rand() % 1000)) / 1000.0;

    // 3. learning rate
    double LR = 1e-3;

    // 4. epoch counter
    int epoch = 0, MAX_EPOCH = 10000;
    bool error;
    double u;

    // print initial synaptic weights
    for (int i=0; i<19; i++)
        printf("w[%d] = %lf\n",i, w[i]);

    // 5. training - 70%
    do {
        // initially, there is no error
        error = false;
        for (int i=0; i<70*ix/100; i++)
        {
            u = 0.0;
            // calculate summation to signal
            for (int j=0; j<19; j++)
                u += (w[j] * x[i][j]);
            // apply activation function
            y[i] = signal(u);
            // if there was a classification error
            if (y[i] != d[i])
            {
                // update synaptic weights
                for (int j=0; j<19; j++)
                    w[j] += ((LR) * ((double)(d[i]-y[i])) * ((double)x[i][j]));
                // mark that there was an error
                error = true;
            }
        }
        epoch++;
    } while (error && epoch < MAX_EPOCH);

    // print number of epochs
    printf("epochs: %d\n", epoch);

    // print initial synaptic weights
    for (int i=0; i<19; i++)
        printf("w[%d] = %lf\n",i, w[i]);

    // 6. classification - 30%
    int correct = 0, incorrect = 0;
    for (int i=(70*ix/100)+1; i<ix; i++)
    {
        u = 0.0;
        // calculate summation to signal
        for (int j=0; j<19; j++)
            u += (w[j] * x[i][j]);
        // apply activation function
        y[i] = signal(u);
        // 7. evaluation
        if (y[i] == d[i]) correct++;
        else incorrect++;
    }

    // 8. display classification results
    printf("Correct: %d/%d (%lf)\n", correct, correct+incorrect, ((double)(correct))/((double)(correct+incorrect)));
    printf("Incorrect: %d/%d (%lf)\n", incorrect, correct+incorrect, ((double)(incorrect))/((double)(correct+incorrect)));

    return 0;
}
