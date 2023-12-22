from datetime import datetime

def so_sanh_ngay(ngay1, ngay2, dinh_dang="%d/%m/%Y"):
    ngay1_obj = datetime.strptime(ngay1, dinh_dang)
    ngay2_obj = datetime.strptime(ngay2, dinh_dang)

    if ngay1_obj < ngay2_obj:
        return f"{ngay1} trước {ngay2}"
    elif ngay1_obj > ngay2_obj:
        return f"{ngay2} trước {ngay1}"
    else:
        return f"{ngay1} và {ngay2} là cùng một ngày"

# Thử nghiệm hàm
ngay_truoc = so_sanh_ngay("20/01/2023", "22/12/2023")
print(ngay_truoc)
