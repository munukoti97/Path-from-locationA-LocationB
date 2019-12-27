public class ShortestPath {

	public int[] d = new int[50];
	public int length = -1, count = 0;

	public int fastestRoute(int[] from, int[] to, int locationA, int localtionB) {
		int[] a = from;
		int[] b = to;
		int i, j, n, max, fro, end;
		int[][] c = new int[50][50];
		fro = locationA;
		end = localtionB;
		n = from.length;

		max = a[0];
		for (i = 0; i < n; i++) {
			c[a[i]][b[i]] = 1;
			c[b[i]][a[i]] = 1;
			if (max < a[i] || max < b[i])
				if (max < a[i])
					max = a[i];
				else
					max = b[i];
		}
		sp(c, fro, end, count, max);
		return length;
	}

	public void sp(int c[][], int fro, int end, int count, int max) {
		int count1 = 1, i, j;
		d[count] = fro;
		if (fro != end) {
			for (i = 0; i <= max; i++) {
				if (c[fro][i] == 1) {
					for (j = 0; j < count; j++)
						if (i == d[j]) {
							count1 = 0;
							break;
						}
					if (count1 == 1) {
						count++;
						sp(c, i, end, count, max);
						d[count] = 0;
						count--;
					}
					count1 = 1;
				}
			}
		} else {
			if (length > count || length == -1)
				length = count;
		}
	}

	public static void main(String[] args) {

		ShortestPath d = new ShortestPath();
		int x = d.fastestRoute(new int[] { 0, 1 }, new int[] { 2, 3 }, 0, 1);
		System.out.println(x);
	}

}
