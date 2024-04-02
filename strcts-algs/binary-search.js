function binarySearch(array, target) {
    let left = 0;
    let right = array.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (array[mid] === target) {
            return mid;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

function binarySearchTasks(tasks, targetId) {
    let left = 0;
    let right = tasks.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (tasks[mid].id === targetId) {
            return mid;
        } else if (tasks[mid].id < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}