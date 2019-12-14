#ifndef __SORT_H__
#define __SORT_H__
#include <iostream>
#include <vector>

void BubbleSort(std::vector <int>& vec);
void SelectionSort(int* vec, int len);
void InsertionSort(int* vec, int len);
void ShellSort(int* arr, int len);
std::vector<int> MergeSort(std::vector<int>arr, int start, int end);
std::vector<int> Merge(std::vector<int> left, std::vector<int> right);
void QuickSort(int *arr, int left, int right);
void HeapSort(int* arr, int len);
void CountingSort(int* arr, int len);
void BucketSort(int* arr, int len);
void RadixSort(int* arr, int len);
int Partition(int* arr, int left, int right);
#endif


#pragma once
