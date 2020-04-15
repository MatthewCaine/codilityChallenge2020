// codilityChallenge2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& H)
{
    int size = H.size();
    std::vector<int> solutions(size, 0);
    int maxElementSize = *max_element(H.begin(), H.end());
    int maxLeft, maxRight, valueLeft, valueLeftMax, valueRight, valueRightMax, sumLeftMax, sumRightMax;


    for (int i = 0; i < size; i++)
    {
        //if (H[i] == maxElementSize)
        {
            if (i == 0)
            {
                maxRight = *max_element(H.begin() + 1, H.end());
                valueRight = maxRight * (size - 1);
                solutions[i] = valueRight + maxElementSize;
            }
            else if (i == (size -1))
            {
                maxLeft = *max_element(H.begin(), H.end() -1);
                valueLeft = maxLeft * (i);
                solutions[i] = valueLeft + maxElementSize;
            }
            else
            { 
                maxLeft = *max_element(H.begin(), H.begin() + i);
                maxRight = *max_element(H.begin() + i+1, H.end());
                valueLeft = maxLeft * (i);
                valueRight = maxRight * (size - (i + 1));
                valueLeftMax = maxElementSize * (i + 1);
                valueRightMax = maxElementSize * (size - i);
                sumLeftMax = valueLeft + valueRightMax;
                sumRightMax = valueRight + valueLeftMax;
                cout << maxLeft << " " << maxRight << " " << valueLeft << " " << valueLeftMax << " " << valueRight << " " << valueRightMax << " " << sumLeftMax << " " << sumRightMax << endl;
                solutions[i] = (sumLeftMax > sumRightMax) ? sumRightMax : sumLeftMax;
            }
        }
    }

    for (int i : solutions)
        cout << i <<" ";
    cout << endl;

    solutions.erase(remove(solutions.begin(), solutions.end(), 0), solutions.end());

    for (int i : solutions)
        cout << i << " ";
    cout << endl;
    int answer = *min_element(solutions.begin(), solutions.end());
    return answer;
}

int main()
{
    vector<int> x = { 1,23,3,24,5,63,7,8,9,110,11,123,13,14,15,146,17,111,19,20,21 };
    int y = solution(x);
    std::cout << y;
}

