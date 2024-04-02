class SelfOrganizingList {
    constructor() {
        this.list = [];
    }

    add(element) {
        let low = 0;
        let high = this.list.length;

        while (low < high) {
            let mid = Math.floor((low + high) / 2);
            if (element > this.list[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        this.list.splice(low, 0, element);
    }

    remove(element) {
        const index = this.list.indexOf(element);
        if (index > -1) {
            this.list.splice(index, 1);
        }
    }

    print() {
        console.log(this.list);
    }


    //edit so that it just returns, not modifies.
    find(element) {
        const index = this.list.indexOf(element);
        if (index > -1) {
            // Move the element to the front of the list
            this.list.splice(index, 1);
            this.list.unshift(element);
            // Return the new index of the element
            return 0;
        }
        // Return -1 if the element is not found
        return -1;
    }
}