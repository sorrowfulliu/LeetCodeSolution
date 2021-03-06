﻿#include "header.h"

/*

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

进阶:
如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

*/

class MedianFinder1 {
public:
	priority_queue<int, vector<int>, less<int>> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;
	/** initialize your data structure here. */
	MedianFinder1() {}

	void addNum(int num)
	{
		if (maxq.size() != minq.size())
		{
			minq.push(num);
			maxq.push(minq.top());
			minq.pop();
		}
		else
		{
			maxq.push(num);
			minq.push(maxq.top());
			maxq.pop();
		}
	}

	double findMedian()
	{
		return maxq.size() != minq.size() ? minq.top() : (minq.top() + maxq.top()) / 2.0;
	}
};
/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/

//另一种详细的实现
class MedianFinder2 {
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
public:
	/** initialize your data structure here. */
	MedianFinder2() {}

	void addNum(int num)
	{
		if ((maxHeap.size() + minHeap.size()) & 1)
		{
			if (!minHeap.empty() && minHeap.top() < num)
			{
				int temp = minHeap.top();
				minHeap.pop();
				maxHeap.push(temp);
				minHeap.push(num);
			}
			else
			{
				maxHeap.push(num);
			}
		}
		else
		{
			if (!maxHeap.empty() && num < maxHeap.top())
			{
				int temp = maxHeap.top();
				maxHeap.pop();
				minHeap.push(temp);
				maxHeap.push(num);
			}
			else
			{
				minHeap.push(num);
			}
		}
	}

	double findMedian()
	{
		if ((maxHeap.size() + minHeap.size()) & 1) return minHeap.top();
		else return (minHeap.top() + maxHeap.top()) / 2.0;
	}
};
/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/