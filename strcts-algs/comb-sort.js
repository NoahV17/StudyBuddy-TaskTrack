// Functionality
// Comb sort wil be used to sort the list of assignments
// according to how the user would like to display them.
class CombSort {
    constructor(data) {
        this.data = data;
        this.gap = data.length;
        this.shrink = 1.3;
        this.sorted = false;
    }

    prioritySort() {
        const priorityOrder = { 'high': 3, 'medium': 2, 'low': 1 };
        while (!this.sorted) {
            this.gap = Math.floor(this.gap / this.shrink);
            if (this.gap <= 1) {
                this.gap = 1;
                this.sorted = true;
            }
            let i = 0;
            while (i + this.gap < this.data.length) {
                if (priorityOrder[this.data[i].priority] < priorityOrder[this.data[i + this.gap].priority]) {
                    [this.data[i], this.data[i + this.gap]] = [this.data[i + this.gap], this.data[i]];
                    this.sorted = false;
                }
                i++;
            }
        }
    }

    dateSort() {
        while (!this.sorted) {
            this.gap = Math.floor(this.gap / this.shrink);
            if (this.gap <= 1) {
                this.gap = 1;
                this.sorted = true;
            }
            let i = 0;
            while (i + this.gap < this.data.length) {
                if (this.data[i].dueDate > this.data[i + this.gap].dueDate) {
                    [this.data[i], this.data[i + this.gap]] = [this.data[i + this.gap], this.data[i]];
                    this.sorted = false;
                }
                i++;
            }
        }
    }
}