static ssize_t bof_read(struct file *file, char __user *bof, size_t count, loff_t *f_pos) {

    char arr[8] = {0,};

    if (_copy_to_user(buf, arr, count)) {   // oob read 발생
    
        return -EFAULT; 
    
    }

    return 0;

}

static ssize_t bof_write(struct file *file, const char __user *buf, size_t count, loff_t *f_pos) {

    char arr[8] = {0,};

    if (_copy_from_user(arr, buf, count)) {   // bof 발생
    
        return -EFAULT; 
    
    }

    return 0;

}