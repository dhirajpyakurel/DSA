''' Knight Tours The Entire Board'''


# Size Of Chess Board
n=8

#Turtle Graphics Declaration
import turtle
import time
t=turtle.Turtle()
s=turtle.getscreen()
s.title("Knight Travels")
t.shape("turtle")
t.speed(0)
s.bgcolor("Black")


# Graphics Of Chess Board
def Graphic_board(n):

	# Wooden Background
	t.color("#CB5718","#5c280c")
	t.penup()
	t.goto(-400,-400)
	t.pendown()
	t.begin_fill()
	t.forward(670)
	t.left(90)
	t.forward(670)
	t.left(90)
	t.forward(670)
	t.left(90)
	t.forward(670)
	t.left(90)
	t.end_fill()

	# Chess Board
	k=1
	l=1
	t.penup()
	t.goto(-350,-350)
	t.pendown()
	for i in range(n):
		for j in range(n):
			t.begin_fill()
			if (k%2==0):
				t.color("white","White")
			else:
				t.color("Black","Black")	
			k+=1
			t.forward(70)
			t.left(90)
			t.forward(70)
			t.left(90)
			t.forward(70)
			t.left(90)
			t.forward(70)
			t.left(90)
			t.forward(70)
			t.end_fill()
		t.penup()
		t.goto(-350,-350)
		t.left(90)
		t.forward(l*70)
		t.right(90)
		l+=1
		k+=1

	# Initial Position Setup
	t.penup()
	t.goto(-315,-315)
	t.left(90)
	t.color("Red","Blue")
	t.speed(0)
	t.write(0,align="center",font=("Arial",16,"normal"))


# Core Initializations And Finalization
def solve_prob(n):

	# Board Initialization
	board = [[-1 for i in range(n)]for i in range(n)]

	# Knight Move Initializations
	m_x = [2, 1, -1, -2, -2, -1,  1,  2]
	m_y = [1, 2,  2,  1, -1, -2, -2, -1]

	# Board And Knight Initial Position Defination
	board[0][0]=0
	pos = 1
	
	# Graphic Called
	Graphic_board(n)

	# Checking Soln
	if(not check(n, board, 0, 0, m_x, m_y, pos)):
		print("Solution does not exist")
	else:
		print_solution(n, board)


# Backtracking, Checking Moves and Recursion
def check(n, board, c_x, c_y, m_x, m_y, pos):
	if(pos == n**2):
		return True
	
	# Attempting All Moves Till Valid Move Is Found
	for i in range(8):
		n_x = c_x + m_x[i]
		n_y = c_y + m_y[i]
		if(is_safe(n_x, n_y, board)):
			board[n_x][n_y] = pos
			if(check(n, board, n_x, n_y, m_x, m_y, pos+1)):
				return True

			# Backtracking
			board[n_x][n_y] = -1
	return False


# Checking The Validicity Of The Board
def is_safe(x, y, board):
	if(x >= 0 and y >= 0 and x < n and y < n and board[x][y] == -1):
		return True
	return False

# Displaying The Steps In Proper Order
def print_solution(n, board):
	d=1
	x=0
	y=0
	t.speed(0)
	for k in range(64):
		for i in range(0,n):
			for j in range(n):
				if(d==board[i][j]):
					time.sleep(.5)
					t.forward(70*(j-x))
					t.right(90)
					t.forward(70*(i-y))
					t.left(90)
					t.write(board[i][j],align="center",font=("Arial",16,"normal"))
					x=j
					y=i
					d+=1


# Driver Code
if __name__ == "__main__":

	# Function Call
	solve_prob(n)

	# Holding Turtle Screen
	turtle.done()