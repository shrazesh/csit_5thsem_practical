import random

def mod_exp(base, exp, mod):
    return pow(base, exp, mod)

def elgamal_encrypt(p, g, x, message):
    y = mod_exp(g, x, p)

    k = random.randint(1, p - 2)
    a = mod_exp(g, k, p)
    b = (mod_exp(y, k, p) * message) % p

    return {
        "Public Key (p, g, y)": (p, g, y),
        "Private Key (x)": x,
        "Random k": k,
        "Encrypted Message (a, b)": (a, b)
    }

def elgamal_decrypt(p, x, a, b):
    s = mod_exp(a, x, p)
    s_inv = pow(s, -1, p)
    decrypted = (b * s_inv) % p
    return decrypted

def main():
    print("\t")
    print("\t ElGamal Encryption System \t")
    print("\t")
    p = int(input("Enter a prime number p: "))
    g = int(input("Enter a primitive root modulo p (g): "))
    x = int(input("Enter private key x (1 < x < p-1): "))
    message = int(input("Enter message (as integer < p): "))

    encryption_result = elgamal_encrypt(p, g, x, message)
    a, b = encryption_result["Encrypted Message (a, b)"]
    decrypted = elgamal_decrypt(p, x, a, b)

    print("\n--- Result ---")
    for key, value in encryption_result.items():
        print(f"{key}: {value}")
    print(f"Decrypted Message: {decrypted}")

if __name__ == "__main__":
    main()
