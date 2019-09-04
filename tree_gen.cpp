#include <bits/stdc++.h>

// random number generator
std::mt19937 rd(std::random_device{}());

std::vector<int> vertices; 

// Modify here to adapt the generator for different types os trees.
const int VerticesNumber = 25;
const int groupSize = 10; 
// A higher groupsize means that the diameter will be smaller, and a lower groupsize means the opposite.

int main()
{
	for(int i = 1; i <= VerticesNumber; i++) vertices.push_back(i);
	shuffle(vertices.begin(), vertices.end(), rd);

	std::vector<std::pair<int, int>> edges;
	int start = 0, end = VerticesNumber - 1;
	while(start < end)
	{
		// get a random group of vertices
		int group = rd() % groupSize;
		// The group must be in the range of the array
		group = std::min(group, end - start);

		// Connect the group to the first element after it
		for(int i = start; i < start + group and i < VerticesNumber - 1; i++)
		{
			edges.push_back({vertices[i], vertices[start + group]});
		}

		// Now we will connect a group starting in the first element after the actual group.
		start += group;
	}

	// To be sure that there will be no patterns in the order of the edges
	shuffle(edges.begin(), edges.end(), rd);

	if((int)edges.size() != VerticesNumber - 1) throw std::runtime_error("Tree doesn't have the correct number of edges");
	std::cout << VerticesNumber << "\n";
	for(std::pair<int, int> u : edges)
	{
		std::cout << u.first << " " << u.second << "\n";
	}
}
