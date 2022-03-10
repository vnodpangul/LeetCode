for (int k = 0; k < 4; k++) {
int nextRow = curr[0] + shift[k];
int nextCol = curr[1] + shift[k + 1];
if (nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col
&& grid[nextRow][nextCol] == 0 && !isVisited[nextRow][nextCol]) {
//The shortest distance from [nextRow][nextCol] to thic building
// is 'level'.
distance[nextRow][nextCol] += level;
reach[nextRow][nextCol]++;
isVisited[nextRow][nextCol] = true;
myQueue.offer(new int[] {nextRow, nextCol});
}
}
}
level++;
}
}
}
}
int shortest = Integer.MAX_VALUE;
for (int i = 0; i < row; i++) {
for (int j = 0; j < col; j++) {
if (grid[i][j] == 0 && reach[i][j] == buildingNum) {
shortest = Math.min(shortest, distance[i][j]);
}
}
}
return shortest == Integer.MAX_VALUE ? -1 : shortest;
}
}
```