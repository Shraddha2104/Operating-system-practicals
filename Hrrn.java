package os_project;

import java.util.Scanner;

//highest response ratio next(variation of Shortest Job First
//mode:non premptive
//not only favours shorter jobs but also reduces the waiting time of longer jobs.

public class Hrtf {
	private static int sum_b = 0;

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of processes:");
		int n = sc.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		int p[] = new int[n];

		for (int i = 0; i < n; i++) {
			System.out.println("Process id : " + i);
			p[i] = i;
			System.out.println("Enter the arrival and burst time");
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			sum_b = sum_b + b[i];

		}
		Hrtf h = new Hrtf();
		h.sortByArrival(a, b, p, n);
		h.process(a, b, n);

	}

	public void process(int a[], int b[], int n) {
		int tat[] = new int[n];
		int wt[] = new int[n];
		int c[] = new int[n];
		float ntat[] = new float[n];

		float r_ratio = 0, avg_wt = 0;
		int i = a[0];

		while (i < sum_b) {
			float large= -99;
			int pos = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] <= i && c[j] != 1) {
					r_ratio = (b[j] + (i - a[j])) / b[j]; // response ratio
					if (large < r_ratio) // largest response ratio to be taken
					{
						large= r_ratio;
						pos = j;
					}

				}
			}
			i = i + b[pos];
			c[pos] = 1;
			wt[pos] = i - a[pos] - b[pos];
			tat[pos] = i - a[pos];
			ntat[pos] = (float) (tat[pos] / b[pos]);
			avg_wt = wt[pos] + avg_wt;
			System.out.println("ID \t AT \t BT \t wT \t TAT \t NTAT");
			System.out.println(pos + "\t" + a[pos] + "\t" + b[pos] + "\t"
					+ wt[pos] + "\t" + tat[pos] + "\t" + ntat[pos]);

		}
		System.out.println("Average waiting time is is:" + avg_wt / n);

	}

	public void sortByArrival(int a[], int b[], int p[], int n) {
		int temp;
		for (int i = 0; i < n - 1; i++) { // insertion sort
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;

					temp = b[i];
					b[i] = b[j];
					b[j] = temp;

					temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
			}
		}
	}
}
