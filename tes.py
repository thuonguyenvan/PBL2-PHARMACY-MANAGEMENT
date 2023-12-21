import random
import string

def generate_transaction_code(length=10):
    characters = string.ascii_letters + string.digits
    transaction_code = ''.join(random.choice(characters) for i in range(length))
    return transaction_code

# Sử dụng hàm để tạo mã giao dịch
transaction_code = generate_transaction_code()
print("Mã giao dịch mới:", transaction_code)
