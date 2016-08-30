#include <iostream>
#include <vector>
#include <random>

using namespace std;

void print_array(vector<int> const & array);
void merge_sort(vector<int> & array, int left_end, int right_end);
void merge(vector<int> & array, int const& left_end, int const& mid, int const& right_end);

int main()
{
    vector<int> array_of_ints;
    
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<> distribution(-50,50);
     
    for(int i = 0; i < 25; i++)
    {
        array_of_ints.push_back(distribution(generator));
    }
   
    print_array(array_of_ints);
    
    merge_sort(array_of_ints, 0, array_of_ints.size());
    
    print_array(array_of_ints);
    
    return 0;
}

void print_array(vector<int> const & array)
{
    vector<int>::const_iterator itr;
    cout << endl;
    for(itr = array.cbegin(); itr != array.cend(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl << endl;
}

void merge_sort(vector<int> & array, int left_end, int right_end)
{
    if(left_end + 1 < right_end)
    {
        int mid = left_end + (right_end - left_end) / 2;
        merge_sort(array, left_end, mid);
        merge_sort(array, mid , right_end);
        merge(array, left_end, mid, right_end);
    }
}

void merge(vector<int> & array, int const& left_end, int const& mid, int const& right_end)
{
    int current_location = left_end;
    
    vector<int> left_array;
    vector<int> right_array;
    
    for(int i = left_end; i < mid; i++)
    {
        left_array.push_back(array[i]);
    }
    
    for(int i = mid; i < right_end; i++)
    {
        right_array.push_back(array[i]);
    }
    
    int left_array_index = 0;
    int right_array_index = 0;
    
    while(left_array_index < left_array.size() && right_array_index < right_array.size())
    {
        if(left_array[left_array_index] <= right_array[right_array_index])
             array[current_location++] = left_array[left_array_index++];
        else
            array[current_location++] = right_array[right_array_index++];
    }
    
    while(left_array_index < left_array.size())
    {
        array[current_location++] = left_array[left_array_index++];
    }
    
    while(right_array_index < right_array.size())
    {
        array[current_location++] = right_array[right_array_index++];
    }
}
