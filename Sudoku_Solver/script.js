var n=9;
var arr = [[], [], [], [], [], [], [], [], []]
function randoms(){
    const min = 1;
const max = 7;
const randomInt = Math.floor(Math.random() * (max - min + 1)) + min;
return randomInt
}
for (var i = 0; i < 9; i++) {
	for (var j = 0; j < 9; j++) {
		arr[i][j] = document.getElementById(i * 9 + j);

	}
}


var board = [[], [], [], [], [], [], [], [], []]

function FillBoard(board) {
	for (var i = 0; i < 9; i++) {
		for (var j = 0; j < 9; j++) {
			if (board[i][j] != 0) {
				arr[i][j].innerText = board[i][j]
			}

			else
				arr[i][j].innerText = ''
		}
	}
}






let GetPuzzle = document.getElementById('GetPuzzle')
let SolvePuzzle = document.getElementById('SolvePuzzle')


var i=0
GetPuzzle.onclick=function(){
   if(i==0)
   {
    board=
    [
        [0,0,7,1,0,0,0,6,0],
        [1,0,5,2,0,8,0,0,0],
        [6,0,0,0,0,7,1,2,0],
        [3,1,2,4,0,5,0,0,8],
        [0,0,6,0,9,0,2,0,0],
        [0,0,0,0,0,3,0,0,1],
        [0,0,1,0,0,4,9,8,6],
        [8,0,3,9,0,6,0,0,0],
        [0,6,0,0,8,2,7,0,3],
];
   }
   if(i==1) 
   {
    board=
    [
        [3,0,8,4,0,6,5,0,0],
        [0,0,5,0,3,8,7,0,6],
        [9,0,7,5,0,1,3,0,4],
        [7,0,0,0,4,0,0,5,0],
        [8,1,0,2,5,0,0,7,9],
        [5,9,0,0,8,0,0,0,0],
        [2,0,0,8,6,4,9,3,0],
        [0,7,0,0,1,0,0,0,0],
        [4,8,0,7,0,0,0,6,0],

    ];
   }
   if(i==2) 
   {
    board=
    [
        [4,3,0,7,0,0,0,0,6],
        [0,0,6,3,0,0,0,7,5],
        [7,0,0,6,2,4,0,3,8],
        [0,5,0,2,0,0,8,0,4],
        [8,2,4,9,0,1,0,0,0],
        [1,0,0,5,4,0,6,0,2],
        [0,0,0,0,0,0,2,8,9],
        [0,6,0,1,0,0,0,4,0],
        [0,0,0,8,0,0,5,0,1],

    ];
   }

   if(i==3) 
   {
    board=
    [
        [0,0,2,4,8,9,0,3,5],
        [8,0,0,0,5,0,0,4,0],
        [0,0,9,3,0,0,0,2,8],
        [0,0,0,1,0,5,4,0,0],
        [4,1,0,0,0,3,0,6,9],
        [7,6,3,0,0,0,5,0,1],
        [3,9,6,5,4,7,0,0,0],
        [0,0,4,0,0,0,3,5,0],
        [0,5,0,0,0,0,0,9,0],

    ];
   }


    FillBoard(board);
    i++
    if(i==4)
    {
        i=0;
    }
}
SolvePuzzle.onclick = () => {
    
	SudukoSolver(board, 0, 0,9);
};


function isvalid( board, i, j,num, n)
{
    //row and column check
    for(let x=0;x<n;x++){
        if(board[i][x]==num  ||  board[x][j]==num){
            return false;
        }
    }

    // submatrix check
    let rn=Math.sqrt(n);
    let si = i - i % rn;
    let sj = j - j % rn;
    for (let x= si; x < si+rn; x++)
    {
        for (let y = sj; y < sj+rn ; y++)  // Fixed stopping condition here
        {
            if (board[x][y] == num)
            {
                return false;
            }
        }
    }
    return true;
}


function SudukoSolver( board,i, j, n)
{
//base case

   if(i==n)
   {
      FillBoard(board);
       return true;
   }

   //if we are not inside the board
   if(j==n)
   {
       return SudukoSolver(board,i+1,0,n);
   }

   //if cell is already solved move forward
   if(board[i][j]!=0)
   {
       return SudukoSolver(board,i,j+1,n);
   }
   //we try to fill the approprite number here

   for(let num=1;num<=9;num++)
   {
    //check number can be filled or not
     if  ( isvalid(board,i,j,num,n))
      {
        board[i][j]=num;
        let subAns=SudukoSolver(board,i,j+1,n);
        if(subAns)
        {
            return true;
        }
//backtrking _______ undo the changes:

         board[i][j]=0;

      }
   }
   return false;

} 