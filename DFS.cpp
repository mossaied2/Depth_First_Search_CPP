// C++ Code implementation for DFS
#include <iostream> // cout 
#include <queue> // FIFO queue
#include <array> 
#include <map> // dictionary
#include <conio.h> // getch()
#include <thread>
#include <chrono>
#include <stack>
using namespace std;

// The following variable are used for debugging and have no relation to DFS
// You can change the following based on your preference 
const bool verbose_output = false; // To see the expansion or the exploration step by step, amek this variable true
const bool break_output = true; // if true the user must hit the keyboard after each step
const bool slow_output = true; // if true wait_period of time is put between each 2 explorations 
const int wait_period = 100;// wait time between 2 explorations in milliseconds 

// the following are the 9 maps that you can try to verify you are getting the correct results for DFS
// choose the map by defining the corresponding Example. For example if you want Example 3, change Example_# in below to Example_3
#define Example_9 true

// Based on the previous macro, only map is choosen
#ifdef Example_1
const int ROW_SIZE = 4;	
const int COL_SIZE = 4;	
char grid[][COL_SIZE] = {
	{ '1', '0', '1', 'S' },		
	{ '0', '1', '0', '0' },		
	{ '1', '0', '0', '0' },		
	{ 'G', '0', '0', '0' }
};
#elif Example_2
const int ROW_SIZE = 10;
const int COL_SIZE = 10;
char grid[][COL_SIZE] = {
	{ 'S', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', 'G' }
};
#elif Example_3
const int ROW_SIZE = 10;
const int COL_SIZE = 10;
char grid[][COL_SIZE] = {
	{ 'S', '0', '0', '0', '0', '0', '0', '0', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', 'G' }
};
#elif Example_4
const int ROW_SIZE = 10;
const int COL_SIZE = 10;
char grid[][COL_SIZE] = {
	{ 'S', '0', '0', '0', '0', '1', '1', '1', '1', 'G' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '1', '1', '1', '1', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' }
};
#elif Example_5
const int ROW_SIZE = 10;
const int COL_SIZE = 5;
char grid[][COL_SIZE] = {
	{ '0', '0', '0', '1', '1' },
	{ '1', '0', 'G', '1', '1' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', 'S', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '1', '1', '0', '0' }
};
#elif Example_6
const int ROW_SIZE = 10;
const int COL_SIZE = 5;
char grid[][COL_SIZE] = {
	{ '1', '0', '0', '0', '1' },
	{ '1', '0', '1', '0', '0' },
	{ '1', 'G', '1', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', 'S', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '1', '1', '0', '0' }
};
#elif Example_7
const int ROW_SIZE = 10;
const int COL_SIZE = 5;
char grid[][COL_SIZE] = {
	{ '1', '0', '0', '0', '1' },
	{ '1', '0', '1', '0', '0' },
	{ '1', '0', '1', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', 'S', '0', 'G', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '1', '1', '0', '0' }
};
#elif Example_8
const int ROW_SIZE = 10;
const int COL_SIZE = 5;
char grid[][COL_SIZE] = {
	{ '0', '0', '0', '0', '1' },
	{ '1', '0', '1', '0', '0' },
	{ '1', 'G', '1', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', 'S', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '1', '1', '0', '0' }
};
#elif Example_9
const int ROW_SIZE = 10;
const int COL_SIZE = 5;
char grid[][COL_SIZE] = {
	{ '1', '0', '0', '0', '1' },
	{ '1', '0', '1', '0', '0' },
	{ '1', 'G', '1', '0', '0' },
	{ '1', '1', '1', '1', '1' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', 'S', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '1', '1', '0', '0' }
};
#endif // choose_map 

// The below function shows the map
void show_map(char input_map[ROW_SIZE][COL_SIZE]) {
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			std::cout << input_map[i][j] << "\t";
		}
		std::cout << endl;
	}

	if(verbose_output){
		cout << endl << "Notations:\n"
			"F: Current frontier \t E: Previously explored frontier \t S: Start node \t G: Goal node \n"
			"*: Descovered Node \t 0: Free & unexplored node \t 1:Obstacle" << endl ;
	}

	if (break_output)
		_getch();

	if (slow_output)
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_period));

}

/*no need for parent array here*/
/*
// Initialize parent array with -1 (-1 means no parent or in otherwords the cell is not explored or descovered by any frontier)
void initialize_parents(int map_size, map<int, int> & parent) {
	for (int i = 0; i < map_size; i++) {
		parent.insert(pair<char, int>(i, -1)); //-1 means no parent
	}
}
*/


// The below is defining the entry of each location in the queue. Each cell is defined by its col, row, id and real distance (real distance = exploration step BTW) 
// from start node
// QItem for current location and distance from start location 
class QItem {
public:
	int row;
	int col;
	int id;
	int dist;
	QItem(int x, int y, int ID,  int w)
		: row(x), col(y), id(ID), dist(w)
	{
	}
};

// Here is the real DFS function 
int DFS(stack<QItem> & q, char grid[ROW_SIZE][COL_SIZE], bool visited[ROW_SIZE][COL_SIZE], /*map<int, int> & parent,*/ int & start_node_id, int & goal_node_id)
{
	QItem start(0, 0, 0, 0);

	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++)
		{
			if (grid[i][j] == '1') // if barrier
				visited[i][j] = true; // mark visited
			else
				visited[i][j] = false;

			// Finding start 
			if (grid[i][j] == 'S')
			{
				start.row = i;
				start.col = j;
				start.id = i + ROW_SIZE * j;
				start_node_id = i + ROW_SIZE * j;
			}

			// Finding goal 
			if (grid[i][j] == 'G')
			{
				goal_node_id = i + ROW_SIZE * j;
			}
		}
	}

	// applying DFS on matrix cells starting from start node
	/**********************************************************************************************************/
	// Start: Use a different data structure (search for LIFO or stack in c++)
	//stack<QItem> q;
	// End: Use a different data structure (search for LIFO or stack in c++)
	/**********************************************************************************************************/
	
	q.push(start);
	visited[start.row][start.col] = true;
	while (!q.empty()) {
		/**********************************************************************************************************/
		// Start: read the head or the top element of the stack
		QItem p = q.top();
		// End: read the head or the top element of the stack
		/**********************************************************************************************************/

		// check if the current frontier is the goal
		if (grid[p.row][p.col] == 'G') { 
			return true; // break the loop and return minimum hops (min distance in uniform grid)
		}

		// Show the current Frontier
		if (verbose_output && grid[p.row][p.col] != 'S') {
			grid[p.row][p.col] = 'F';

			show_map(grid);
		}

		// moving up 
		if (p.row - 1 >= 0 &&
			visited[p.row - 1][p.col] == false) {
			// ID = (col_index) * col size + row_index 
			int id = (p.row - 1) + ROW_SIZE * p.col;
			q.push(QItem(p.row - 1, p.col, id, p.dist + 1));
			//parent[id] = p.id;
			visited[p.row - 1][p.col] = true;

			/**********************************************************************************************************/
			// Start: continue once you discovered a new node
			continue;
			// End: continue once you discovered a new node
			/**********************************************************************************************************/

			// Show the new discovered node
			if (verbose_output){
				if(grid[p.row - 1][p.col] != 'G')
					grid[p.row - 1][p.col] = '*';
				show_map(grid);
			}
		}

		// moving right 
		if (p.col + 1 < COL_SIZE &&
			visited[p.row][p.col + 1] == false) {
			// ID = (col_index) * col size + row_index 
			int id = p.row + ROW_SIZE * (p.col + 1);
			q.push(QItem(p.row, p.col + 1, id, p.dist + 1));
			//parent[id] = p.id;
			visited[p.row][p.col + 1] = true;

			/**********************************************************************************************************/
			// Start: continue once you discovered a new node
			continue;
			// End: continue once you discovered a new node
			/**********************************************************************************************************/

			// Show the new discovered node
			if (verbose_output) {
				if (grid[p.row][p.col + 1] != 'G')
					grid[p.row][p.col + 1] = '*';
				show_map(grid);
			}
		}

		// moving left 
		if (p.col - 1 >= 0 &&
			visited[p.row][p.col - 1] == false) {
			int id = p.row + ROW_SIZE * (p.col - 1);
			q.push(QItem(p.row, p.col - 1, id, p.dist + 1));
			//parent[id] = p.id;
			visited[p.row][p.col - 1] = true;

			/**********************************************************************************************************/
			// Start: continue once you discovered a new node
			continue;
			// End: continue once you discovered a new node
			/**********************************************************************************************************/

			// Show the new discovered node
			if (verbose_output) {
				if (grid[p.row][p.col - 1] != 'G')
					grid[p.row][p.col - 1] = '*';
				show_map(grid);
			}
		}

		// moving down 
		if (p.row + 1 < ROW_SIZE &&
			visited[p.row + 1][p.col] == false) {
			// ID = (col_index) * col size + row_index 
			int id = (p.row + 1) + ROW_SIZE * p.col;
			q.push(QItem(p.row + 1, p.col, id, p.dist + 1));
			//parent[id] = p.id;
			visited[p.row + 1][p.col] = true;

			/**********************************************************************************************************/
			// Start: continue once you discovered a new node
			continue;
			// End: continue once you discovered a new node
			/**********************************************************************************************************/

			// Show the new discovered node
			if (verbose_output) {
				if (grid[p.row + 1][p.col] != 'G')
					grid[p.row + 1][p.col] = '*';
				show_map(grid);
			}
		}

/**********************************************************************************************************/
		// Start: if all neighbors around a node is expolored then pop this node becuase no more node a rounf to descover
		q.pop();
		// End: if all neighbors around a node is expolored then pop this node becuase no more node a rounf to descover
/**********************************************************************************************************/

		// mark the current frontier as Explored (E) and the show the map
		if (verbose_output) {
			if (grid[p.row][p.col] == 'F') {
				grid[p.row][p.col] = 'E';
				show_map(grid);
			}
		}

	}

	// In case this line is reached, then that means no route between start and goal. We mark that by min distance = -1
	return false;
}

// get the closest neighbor to the start node
// the content of this function shoud be part of the home work 
void get_closest_neighbor(queue<int> route_nodes, stack<QItem> Stack, int & closest_neighbor, const int & row_current, const int & col_current, const int & start_node_id) {
	int min_dist = ROW_SIZE*COL_SIZE; // ROW_SIZE*COL_SIZE > max_dist = ROW_SIZE+COL_SIZE

	int row_start = start_node_id % ROW_SIZE;
	int col_start = (start_node_id - row_current) / ROW_SIZE;

	for (int n = 0; n < 4; n++) {
		stack<QItem> q1 = Stack;
		queue<int> q2 = route_nodes;
		int neighbor_id, dist;
		if (n == 0) { // check up
			if ((row_current - 1) < 0)
				continue;
			if (grid[row_current - 1][col_current] == '1')
				continue;

			neighbor_id = (row_current - 1) + ROW_SIZE * col_current;
			dist = abs(row_current - 1 - row_start) + abs(col_current - col_start);
		}
		else if (n == 1) { // check right
			if ((col_current + 1) > (COL_SIZE - 1))
				continue;
			if (grid[row_current][col_current + 1] == '1')
				continue;

			neighbor_id = row_current + ROW_SIZE * (col_current + 1);
			dist = abs(row_current - row_start) + abs(col_current + 1 - col_start);
		}
		else if (n == 2) { // check left
			if ((col_current - 1) < 0)
				continue;
			if (grid[row_current][col_current - 1] == '1')
				continue;

			neighbor_id = (row_current) + ROW_SIZE * (col_current - 1);
			dist = abs(row_current - row_start) + abs(col_current - 1 - col_start);
		}
		else if (n == 3) { // check down
			if ((row_current + 1) > (ROW_SIZE + 1))
				continue;
			if (grid[row_current + 1][col_current] == '1')
				continue;

			neighbor_id = (row_current + 1) + ROW_SIZE * col_current;
			dist = abs(row_current + 1 - row_start) + abs(col_current - col_start);
		}

		bool exist = false;
		while (!q2.empty()) {
			int node = q2.front();
			q2.pop();
			if (node == neighbor_id) {
				exist = true;
				break;
			}
		}
		if (exist)
			continue;

		while (!q1.empty()) {
			QItem node = q1.top();
			q1.pop();
			if (node.id == neighbor_id && dist < min_dist) {
				closest_neighbor = node.id;
				min_dist = dist;
				break;
			}
		}

	}
}

// main function  
int main()
{
	int start_node_id, goal_node_id;
	char input_map[ROW_SIZE][COL_SIZE];

	// copy grid map into input_map 
	memcpy(input_map, grid, sizeof(grid));

	// DFS stack to hold expolred nodes that can connect start to goal
	stack<QItem> Stack;

	// To keep track of visited QItems. Marking blocked cells as visited. By this we avoid extra check if cell is barrier or not
	// At the same time when we descover start or goal nodes we use their col and row indices to find ther ids (start_node_id and goal_node_id)
	bool visited[ROW_SIZE][COL_SIZE];

/*
	// create parent array where parent[i][j] = parent of node [i][j]
	//map<int, int> parent;
	//initialize_parents(sizeof(input_map) / sizeof(input_map[0]), parent);
*/

	// explore the map to find shortest path using DFS
	bool goal_reachable = DFS(Stack, input_map, visited/*, parent*/, start_node_id, goal_node_id);
	
	// if min_dist > 0, then the goal is reachable from the start node 
	if (goal_reachable){

		std::cout << "shortest Path: G <- ";
		int row_current = goal_node_id % ROW_SIZE;
		int col_current = (goal_node_id - row_current) / ROW_SIZE;

		int row_parent, col_parent;

		int closest_neighbor;
		
		queue<int> route_nodes;
		route_nodes.push(goal_node_id);

		while (true) {

			// get the closest neighbor and set as parent
			get_closest_neighbor(route_nodes, Stack, closest_neighbor, row_current, col_current, start_node_id);

			if (closest_neighbor == start_node_id) {
				break;
			}

			route_nodes.push(closest_neighbor);

			std::cout << closest_neighbor << " <- "; 

			row_parent = closest_neighbor % ROW_SIZE;
			col_parent = (closest_neighbor - row_parent) / ROW_SIZE;

			if (row_parent - row_current == -1) {
				input_map[row_parent][col_parent] = 'v';
			}
			else if (row_parent - row_current == 1) {
				input_map[row_parent][col_parent] = '^';
			}
			else if (col_parent - col_current == -1) {
				input_map[row_parent][col_parent] = '>';
			}
			else if (col_parent - col_current == 1) {
				input_map[row_parent][col_parent] = '<';
			}

			row_current = row_parent;
			col_current = col_parent;
		}
		std::cout << "S" << endl;

		// show map with marked shortest route 
		show_map(input_map);
	}
	else
		cout << "No Route from S to D" << endl;

	return 0;
}