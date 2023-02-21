import base64
import ctypes
import ftplib
import re
import time
import tkinter.messagebox
import urllib
import webbrowser
from tkinter import ttk

import requests
import os
import hashlib
import urllib.request
import subprocess
import sys
import tkinter as tk
from ftplib import FTP
from PIL import Image, ImageTk


# Создаем главное окно приложения
root = tk.Tk()
root.title("R2 Online Лаунчер для входа в игру")
#root.overrideredirect(True)
root.resizable(width=False, height=False)

# иконка
root.iconbitmap('icon.ico')



# Определяем начальные координаты мыши и окна
start_x, start_y = 0, 0
window_x, window_y = 0, 0

# Привязываем обработчики событий
def start_drag(event):
    global start_x, start_y, window_x, window_y
    start_x = event.x_root
    start_y = event.y_root
    window_x = root.winfo_x()
    window_y = root.winfo_y()
def drag(event):
    global start_x, start_y, window_x, window_y
    dx = event.x_root - start_x
    dy = event.y_root - start_y
    new_x = window_x + dx
    new_y = window_y + dy
    root.geometry(f"+{new_x}+{new_y}")
def stop_drag(event):
    global start_x, start_y, window_x, window_y
    start_x, start_y, window_x, window_y = 0, 0, 0, 0
root.bind("<ButtonPress-1>", start_drag)
root.bind("<B1-Motion>", drag)
root.bind("<ButtonRelease-1>", stop_drag)



# Анти-инжект
def validate_input(text):
    # Проверяем длину ввода
    if len(text) > 20:
        tk.messagebox.showerror("Error!", f"Поля превышают 20 символов!")
        return False
    # Проверяем, что ввод не содержит специальные символы
    pattern = re.compile(r'[^a-zA-Z0-9]')
    if pattern.search(text):
        return False
    # Проверяем, что ввод не содержит запрещенные ключевые слова SQL
    patternsql = re.compile(r'(\bselect\b|\bdelete\b|\bupdate\b|\binsert\b|\bdrop\b|\bunion\b|\binto\b|\bfrom\b|\bwhere\b|\border by\b|\blimit\b|\bgroup by\b)', re.IGNORECASE)
    if patternsql.search(text):
        return False
    return True


# Создаем виджеты для логина и пароля
login_label = tk.Label(root, text="Логин:")
login_entry = tk.Entry(root)
password_label = tk.Label(root, text="Пароль:")
password_entry = tk.Entry(root, show="*")

# Close Button
close_image = Image.open("close.png")
close_image = close_image.resize((24, 24), resample=Image.LANCZOS)
# устанавливаем прозрачность на максимальный уровень (255)
#close_image.putalpha(0)
close_image = ImageTk.PhotoImage(close_image)
root.close_image = close_image
close_button = tk.Button(root, image=root.close_image, command=root.destroy, bd=0,
                             highlightthickness=0, highlightcolor='#4E443E')



# Анти инжект в окна логина и пароля
def login_def():
    # Получаем введенный логин и пароль
    login = login_entry.get()
    password = password_entry.get()
    # Проверяем, что ввод корректный
    if not validate_input(login) or not validate_input(password):
        print("Некорректный ввод!")
        tk.messagebox.showerror("Error!", f"Поля содержат недопустимые символы!")
        return



# Создаем переключатели RU и CN
language_var = tk.StringVar(value="RU")
ru_radio_button = tk.Radiobutton(root, text="RU", variable=language_var, value="RU")
cn_radio_button = tk.Radiobutton(root, text="CN", variable=language_var, value="CN")

# Создаем кнопки
login_button = tk.Button(root, text="Войти")
register_button = tk.Button(root, text="Регистрация")

# Создаем картинки
discord_image = tk.PhotoImage(file="discord_image.png").subsample(32, 32)
vk_image = tk.PhotoImage(file="vk_image.png").subsample(38, 38)

# Создаем кнопки-картинки
discord_button = tk.Button(root, image=discord_image, command=lambda: webbrowser.open("https://discord.com"))
vk_button = tk.Button(root, image=vk_image, command=lambda: webbrowser.open("https://vk.com/akselrus"))

# Размещаем виджеты на главном окне
# Set background color
root.configure(bg="#4E443E")

# Create and place elements
login_label = tk.Label(root, text="Логин:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
login_label.grid(row=0, column=0, padx=10, pady=10, sticky=tk.W)

login_entry = tk.Entry(root, bg="#FFF", fg="#000", font=("Helvetica", 14))
login_entry.grid(row=0, column=1, padx=10, pady=10)

password_label = tk.Label(root, text="Пароль:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
password_label.grid(row=1, column=0, padx=10, pady=10, sticky=tk.W)

password_entry = tk.Entry(root, bg="#FFF", fg="#000", font=("Helvetica", 14), show="*")
password_entry.grid(row=1, column=1, padx=10, pady=10)

login_button = tk.Button(root, text="Вход", bg="#1E88E5", fg="#FFF", font=("Helvetica", 12))
login_button.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky='nsew')

register_button = tk.Button(root, text="Регистрация", bg="#D81B60", fg="#FFF", font=("Helvetica", 12))
register_button.grid(row=3, column=0, columnspan=2, padx=10, pady=10, sticky='nsew')

close_button.grid(row=0, column=2, padx=10, pady=10, sticky="NE")

discord_button.grid(row=1, column=2, padx=10, pady=10)
discord_button.config(bg="#1E88E5", fg="#FFF", font=("Helvetica", 12))

vk_button.grid(row=2, column=2, padx=10, pady=10)
vk_button.config(bg="#1E88E5", fg="#FFF", font=("Helvetica", 12))

ru_radio_button.grid_remove()
cn_radio_button.grid_remove()


# Создаем кнопки, но не размещаем их на главном окне
options_button = tk.Button(root, text="Настройки")
check_updates_button = tk.Button(root, text="Проверить обновления")
play_button = tk.Button(root, text="Играть")
pass_update = tk.Button(root, text="Обновить пароль")

# Скрываем кнопки
options_button.grid_remove()
check_updates_button.grid_remove()
play_button.grid_remove()
pass_update.grid_remove()

# Кнопка входа
def login_btn():
    user = login_entry.get()
    pass_hash = password_entry.get()

    # Шифруем пароль
    salt = pass_hash  # случайная соль
    hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
    hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
    hash = hex_dig[:20]  # ограничиваем длину до 20 символов

    # Шифруем логин
    salt = user  # случайная соль
    hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
    hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
    user = hex_dig[:20]  # ограничиваем длину до 20 символов

    #hash = base64.b64encode((user).encode('utf-8')).decode('utf-8')
    print(f"Login: {user}, {hash}, {pass_hash}")
    base_address = "http://192.168.86.20:1111"
    params = {
        "user": user,
        "token": hash,
        "isLogin": True
    }
    try:
        response = requests.get(base_address, params=params)
        if response.status_code == 200:
            balance = response.json().get("balance")
            print(f"Balance: {balance}")
            # Set background color and font
            root.configure(bg="#4E443E")

            # Create and place elements
            welcome_label = tk.Label(root, text="Добро пожаловать,", bg="#4E342E", fg="#FFCCBC", font=("Helvetica", 14))
            welcome_label.grid(row=1, column=0, padx=10, pady=10, sticky=tk.E)

            balance_label = tk.Label(root, text=f"Твой баланс: {balance} рублей", bg="#4E342E", fg="#FFCCBC", font=("Helvetica", 13))
            balance_label.grid(row=2, column=0, padx=10, pady=10, sticky=tk.E)


            login_name_label = tk.Label(root, text=login_entry.get(), bg="#4E342E", fg="#FFCCBC",
                                        font=("Helvetica", 14))
            login_name_label.grid(row=1, column=1, padx=10, pady=10, sticky=tk.W)

            discord_button.grid(row=2, column=4, padx=10, pady=10)
            discord_button.config(bg="#1E88E5", fg="#FFF", font=("Helvetica", 12))

            vk_button.grid(row=3, column=4, padx=10, pady=10)
            vk_button.config(bg="#1E88E5", fg="#FFF", font=("Helvetica", 12))

            ru_radio_button.grid(row=2, column=3, padx=10, pady=10, sticky=tk.E)
            ru_radio_button.config(bg="#4E443E", fg="#D81B60", font=("Helvetica", 12))

            cn_radio_button.grid(row=3, column=3, padx=10, pady=10, sticky=tk.E)
            cn_radio_button.config(bg="#4E443E", fg="#D81B60", font=("Helvetica", 12))

            close_button.grid(row=0, column=4, padx=10, pady=10, sticky="NE")

            def on_enter(event):
                event.widget.config(bg="#654321")

            def on_leave(event):
                event.widget.config(bg="#4E443E")

            def on_click(event):
                event.widget.config(bg="#654321")

            ru_radio_button.bind("<Button-1>", on_click)
            cn_radio_button.bind("<Button-1>", on_click)

            ru_radio_button.bind("<Enter>", on_enter)
            ru_radio_button.bind("<Leave>", on_leave)
            ru_radio_button.bind("<Button-1>", on_enter)

            cn_radio_button.bind("<Enter>", on_enter)
            cn_radio_button.bind("<Leave>", on_leave)
            cn_radio_button.bind("<Button-1>", on_enter)

            play_button.grid(row=4, column=0, padx=10, pady=10)
            play_button.config(bg="#43A047", fg="#FFF", font=("Helvetica", 12))


            pass_update.grid(row=4, column=1, padx=10, pady=10)
            pass_update.config(bg="#4385a0", fg="#FFF", font=("Helvetica", 12))

            options_button.grid(row=4, column=2, padx=10, pady=10)
            options_button.config(bg="#D81B60", fg="#FFF", font=("Helvetica", 12))

            check_updates_button.grid(row=4, column=3, padx=10, pady=10)
            check_updates_button.config(bg="#FFB900", fg="#FFF", font=("Helvetica", 12))

            login_label.grid_remove()
            login_entry.grid_remove()
            password_label.grid_remove()
            password_entry.grid_remove()
            register_button.grid_remove()
            login_button.grid_remove()
        else:
            # display error message
            tk.messagebox.showerror("Ошибка!", "Неверный логин или пароль")
            return 401
        return response.status_code

    except requests.exceptions.RequestException as e:
        tk.messagebox.showerror("Ошибка!", f"Неверный логин или пароль. \n\r {e}")
        return 401

# Кнопка играть
def play_btn():
    user = login_entry.get()
    pass_hash = password_entry.get()
    r_login = login_entry.get()

    # Шифруем пароль
    salt = pass_hash  # случайная соль
    hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
    hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
    hash = hex_dig[:20]  # ограничиваем длину до 20 символов

    # Шифруем логин
    salt = user  # случайная соль
    hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
    hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
    user = hex_dig[:20]  # ограничиваем длину до 20 символов

    #hash = base64.b64encode((user).encode('utf-8')).decode('utf-8')
    print(f"Play: {user}, {r_login}, {hash}, {pass_hash}")
    base_address = "http://192.168.86.20:1111"
    language = language_var.get()
    params = {
        "user": user,
        "token": hash,
        "r_login": r_login,
        "isLogin": True
    }
    try:
        response = requests.get(base_address, params=params)
        if response.status_code == 200:
            try:
                root_path = os.getcwd()

                ftp = ftplib.FTP('192.168.56.1')
                ftp.login(user='R2FTP', passwd='R2FTP')

                R2cfg_remote_path = 'R2.cfg'
                # Получить размер файла на сервере
                remote_file_size = ftp.size(R2cfg_remote_path)

                R2cfg_client = os.path.join(root_path, "R2.cfg")

                # Получить размер локального файла
                with open(R2cfg_client, 'rb') as f:
                    local_file_size = len(f.read())

                if remote_file_size != local_file_size:
                    # Скачать файл с сервера
                    with open(R2cfg_client, 'wb') as f:
                        ftp.retrbinary('RETR ' + R2cfg_remote_path, f.write)
                    print('Файл обновлен')
                else:
                    print('Файлы совпадают')

                ftp.quit()
                # Run R2ClientRU.exe process
                hash_str = base64.b64encode((user + hash).encode('utf-8')).decode('utf-8')
                # Юзаем user для клиента , хеш для шифра
                user_hash = base64.b64encode((user).encode('utf-8')).decode('utf-8')

                cmd_args = [f'R2Client{language}.exe',
                            f'"P=&H1=&H2=MTEwMDQ=&P0={user_hash}&P1=Q19SMg==&P2=NDYxMg==&P3=&P4={hash_str}&P5=&PC1=Tg==&PC2=Tg=="']
                print(cmd_args)
                if sys.platform.startswith('win'):
                    ctypes.windll.shell32.ShellExecuteW(None, "runas", cmd_args[0], " ".join(cmd_args[1:]), None, 1)
                else:
                    subprocess.Popen(cmd_args, shell=True, preexec_fn=os.setuid(0))
                    # subprocess.Popen(cmd_args)
            except FileNotFoundError as e:
                tk.messagebox.showerror("Ошибка!", f"R2Client{language}.exe не найден!\n\r{e}")
        else:
            tk.messagebox.showerror("Ошибка!", f"R2Client{language}.exe не найден!")




    except requests.exceptions.RequestException as e:
        tk.messagebox.showerror("Ошибка!", f"Возникла ошибка: {e}")
        return 401

# Кнопка настройки
def launch_options_btn():
    language = language_var.get()
    try:
        root_path = os.getcwd()
        options_path = os.path.join(root_path, f"R2Option{language}.exe")
        #options_path = os.path.join("R2Option", f"R2Option{language}.exe")
        os.startfile(options_path)
    except FileNotFoundError:
        tk.messagebox.showinfo("Ошибка!", f"Файл: R2Option{language}.exe не найден!")

# Кнопка "Проверить обновления"
def check_updates_btn():
    global FTP_HOST, ftp_user, ftp_pass

    user = login_entry.get()
    pass_hash = password_entry.get()
    r_login = login_entry.get()

    # Шифруем пароль
    salt = pass_hash  # случайная соль
    hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
    hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
    hash = hex_dig[:20]  # ограничиваем длину до 20 символов

    # Шифруем логин
    salt = user  # случайная соль
    hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
    hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
    user = hex_dig[:20]  # ограничиваем длину до 20 символов


    base_address = "http://192.168.86.20:1111"
    params = {
        "user": user,
        "token": hash,
        "r_login": r_login,
        "isUpdate": True
    }

    url = base_address + "?" + urllib.parse.urlencode(params)
    print(url)

    try:
        response = requests.get(base_address, params=params, timeout=10)
        #print(response)
        if response.status_code == 200:
            # Получаем логин и пароль FTP из ответа API
            ftp_user = response.json().get("ftp_user")
            ftp_pass = response.json().get("ftp_pass")
            print(ftp_pass, ftp_user)

            FTP_HOST = "192.168.56.1"

            GuiRfsUrl = "gui.rfs"
            EtcRfsUrl = "etc.rfs"

            # Client
            # определяем путь к корневому каталогу
            root_path = os.getcwd()

            GuiRfsFilePath = os.path.join(root_path, "gui", "gui.rfs")
            EtcRfsFilePath = os.path.join(root_path, "etc", "etc.rfs")
        elif response.status_code == 404:
            tk.messagebox.showerror("Ошибка!", "Сервер обновлений отключен!")

        with FTP(FTP_HOST, user=ftp_user, passwd=ftp_pass) as ftp:
            ftp.set_pasv(True)
            print(ftp.getwelcome())

            MAX_RETRIES = 3
            SLEEP_TIME = 5

            for i in range(MAX_RETRIES):
                try:
                    with open(GuiRfsUrl, "wb") as gui_rfs_file:
                        ftp.retrbinary(f"RETR {GuiRfsUrl}", gui_rfs_file.write)
                    with open(EtcRfsUrl, "wb") as etc_rfs_file:
                        ftp.retrbinary(f"RETR {EtcRfsUrl}", etc_rfs_file.write)

                    with open(GuiRfsUrl, "rb") as gui_rfs_file:
                        gui_rfs_md5 = hashlib.md5(gui_rfs_file.read()).hexdigest()

                        with open(GuiRfsUrl + ".md5", "w") as gui_rfs_md5_file:
                            gui_rfs_md5_file.write(gui_rfs_md5)

                    with open(EtcRfsUrl, "rb") as etc_rfs_file:
                        etc_rfs_md5 = hashlib.md5(etc_rfs_file.read()).hexdigest()

                        with open(EtcRfsUrl + ".md5", "w") as etc_rfs_md5_file:
                            etc_rfs_md5_file.write(etc_rfs_md5)

                    break

                except Exception as ex:
                    print(f"Failed to download file, retrying in {SLEEP_TIME} seconds ({i + 1}/{MAX_RETRIES}): {ex}")
                    time.sleep(SLEEP_TIME)
            else:
                # Raise an exception if all retries fail
                raise Exception(f"Failed to download file after {MAX_RETRIES} attempts")

            with open(EtcRfsFilePath, "rb") as EtcRfsFilePath:
                local_gui_rfs_md5 = hashlib.md5(EtcRfsFilePath.read()).hexdigest()
            #print(local_gui_rfs_md5, gui_rfs_md5)
            # print(gui_rfs_md5)
            with open(GuiRfsFilePath, "rb") as GuiRfsFilePath:
                local_etc_rfs_md5 = hashlib.md5(GuiRfsFilePath.read()).hexdigest()
                print(f"GUI: {local_gui_rfs_md5}, {etc_rfs_md5}")
                print(f"ETC: {local_etc_rfs_md5}, {gui_rfs_md5}")
                # print(etc_rfs_md5)
            # проверка хеша между FTP и клиентом
            if local_gui_rfs_md5 != etc_rfs_md5 or local_etc_rfs_md5 != gui_rfs_md5:
                result = tk.messagebox.askquestion("Найдено обновление", "Найдено обновление, хотите обновиться?")

                if result == "yes":
                    # Download and replace files
                    for i, (file, directory) in enumerate([(GuiRfsUrl, "gui"), (EtcRfsUrl, "etc")]):
                        with open(file, "wb") as ftp_file:
                            ftp.retrbinary(f"RETR {file}", ftp_file.write)
                        local_file_path = os.path.join(root_path, directory, os.path.basename(file))
                        os.replace(file, local_file_path)

                        progress_var2 = ((i + 1) * 100 // 2)
                        tk.messagebox.showinfo(f"{progress_var2}", f"{progress_var2}")
                    tk.messagebox.showinfo("Успешно!", "Обновление успешно!")
                else:
                    def update_game():
                        # Download and replace files
                        for file, directory in [(GuiRfsUrl, "gui"), (EtcRfsUrl, "etc")]:
                            with open(file, "wb") as ftp_file:
                                ftp.retrbinary(f"RETR {file}", ftp_file.write)
                            local_file_path = os.path.join(root_path, directory, os.path.basename(file))
                            os.replace(file, local_file_path)
                            progress_var2 = ((i + 1) * 100 // 2)
                            tk.messagebox.showinfo(f"{progress_var2}", f"{progress_var2}")
                        tk.messagebox.showinfo("Успешно!", "Обновление успешно!")
                        update_window.destroy()

                    # Create the main window
                    update_window = tk.Tk()
                    update_window.title("Внимание!")
                    update_window.configure(bg="#4E443E")

                    # Add a label to the window
                    update_label = tk.Label(update_window, text="Клиент должен быть последней версии для игры!", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
                    update_label.pack(pady=20)

                    # Add the update button
                    update_button = tk.Button(update_window, text="Обновить", bg="#1E88E5", fg="#FFF", font=("Helvetica", 12), command=update_game)
                    update_button.pack(pady=10)
                    # Add the exit button
                    def exit_game():
                        update_window.destroy()
                        sys.exit()
                    exit_button = tk.Button(update_window, text="Выход", bg="#D81B60", fg="#FFF", font=("Helvetica", 12), command=exit_game)
                    exit_button.pack(pady=10)
                    # Start the main loop
                    update_window.mainloop()
            else:
                tk.messagebox.showinfo("Обновление", "Клиент обновлен до последней версии.")

            # Disconnect from FTP
            ftp.quit()

    except Exception as e:
        print(e)
        tk.messagebox.showinfo("Ошибка!", f"{e}")

# Кнопка регистрации
def reg_def():
    # Получаем введенный логин и пароль
    login = login_entry.get()
    password = password_entry.get()
    # Проверяем, что ввод корректный
    if not validate_input(login) or not validate_input(password):
        print("Некорректный ввод!")
        tk.messagebox.showerror("Error!", f"Поля содержат недопустимые символы!")
        return
def register_def():
    root.withdraw()
    # Создаем новое окно для регистрации
    register_window = tk.Toplevel(root)
    register_window.title("Регистрация")
    # Убираем рамку окна
    register_window.overrideredirect(True)
    # Set background color
    register_window.configure(bg="#4E443E")


    # Определяем начальные координаты мыши и окна
    start_x, start_y = 0, 0
    window_x, window_y = 0, 0

    # Создаем виджеты для ввода логина, пароля и адреса электронной почты
    reg_label = tk.Label(register_window, text="Регистрация аккаунта:", bg="#4E443E", fg="#ffe7c9", font=("Helvetica", 16))
    login_label = tk.Label(register_window, text="Логин:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
    login_entry = tk.Entry(register_window, bg="#FFF", fg="#000", font=("Helvetica", 14))
    password_label = tk.Label(register_window, text="Пароль:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
    password_entry = tk.Entry(register_window, bg="#FFF", fg="#000", font=("Helvetica", 14), show="*")
    email_label = tk.Label(register_window, text="Email:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
    email_entry = tk.Entry(register_window, bg="#FFF", fg="#000", font=("Helvetica", 14))

    # Создаем кнопку "Зарегистрироваться" и функцию для ее обработки
    def do_register():

        user = login_entry.get()
        pass_hash = password_entry.get()
        email = email_entry.get()
        r_login = login_entry.get()

        # Проверяем, что ввод корректный
        if not validate_input(user) or not validate_input(pass_hash):
            print("Некорректный ввод!")
            tk.messagebox.showerror("Error!", f"Поля содержат недопустимые символы!")
            return

        # Шифруем пароль
        salt = pass_hash  # случайная соль
        hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
        hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
        hash = hex_dig[:20]  # ограничиваем длину до 20 символов

        # Шифруем логин
        salt = user  # случайная соль
        hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
        hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
        user = hex_dig[:20]  # ограничиваем длину до 20 символов

        # hash = base64.b64encode((user).encode('utf-8')).decode('utf-8')
        print(f"Register: {user}, {hash}, {pass_hash}")
        base_address = "http://192.168.86.20:1111"



        params = {
            "user": user,
            "token": hash,
            "email": email,
            "r_login": r_login,
            "isRegister": True
        }
        try:
            response = requests.get(base_address, params=params)
            if response.status_code == 200:
                try:
                    tk.messagebox.showinfo("Успешно!", f"Успешная регистрация!")
                except Exception as e:
                    tk.messagebox.showerror("Ошибка!", f"Логин {user} занят!")

            # Закрываем окно регистрации
            register_window.destroy()
            # Снова открываем окно логина
            root.deiconify()

        except requests.exceptions.RequestException as e:
            tk.messagebox.showerror("Ошибка!", f"Возникла ошибка: {e}")
        return 401

    # Обработчик нажатия кнопки мыши
    def start_drag(event):
        nonlocal start_x, start_y, window_x, window_y
        start_x = event.x_root
        start_y = event.y_root
        window_x = register_window.winfo_x()
        window_y = register_window.winfo_y()

    # Обработчик перемещения мыши
    def drag(event):
        nonlocal start_x, start_y, window_x, window_y
        dx = event.x_root - start_x
        dy = event.y_root - start_y
        new_x = window_x + dx
        new_y = window_y + dy
        register_window.geometry(f"+{new_x}+{new_y}")

    # Обработчик отпускания кнопки мыши
    def stop_drag(event):
        nonlocal start_x, start_y, window_x, window_y
        start_x, start_y, window_x, window_y = 0, 0, 0, 0

    # Привязываем обработчики событий
    register_window.bind("<ButtonPress-1>", start_drag)
    register_window.bind("<B1-Motion>", drag)
    register_window.bind("<ButtonRelease-1>", stop_drag)

    close_image = Image.open("close.png")
    close_image = close_image.resize((24, 24), resample=Image.LANCZOS)
    # устанавливаем прозрачность на максимальный уровень (255)
    #close_image.putalpha(0)
    close_image = ImageTk.PhotoImage(close_image)
    register_window.close_image = close_image
    close_button = tk.Button(register_window, image=register_window.close_image, command=register_window.destroy, bd=0,
                             highlightthickness=0, highlightcolor='#4E443E')

    #close_button.place(x=325 , y=0)


    register_button = tk.Button(register_window, text="Зарегистрироваться", command=do_register)
    register_button.config(bg="#D81B60", fg="#FFF", font=("Helvetica", 12))

    PADX = 10
    PADY = 10

    # Set up the grid layout for the labels, input fields, and buttons
    reg_label.grid(row=0, column=0, padx=PADX, pady=PADY, sticky="NE")
    close_button.grid(row=0, column=1, padx=PADX, pady=PADY, sticky="NE")

    login_label.grid(row=1, column=0, padx=PADX, pady=PADY, sticky="W")
    login_entry.grid(row=1, column=1, padx=PADX, pady=PADY, sticky="E")

    password_label.grid(row=2, column=0, padx=PADX, pady=PADY, sticky="W")
    password_entry.grid(row=2, column=1, padx=PADX, pady=PADY, sticky="E")

    email_label.grid(row=3, column=0, padx=PADX, pady=PADY, sticky="W")
    email_entry.grid(row=3, column=1, padx=PADX, pady=PADY, sticky="E")

    register_button.grid(row=4, column=0, columnspan=2, padx=PADX, pady=PADY, sticky="EW")

# Кнопка обновления пароля
def upd_pass():
    root.withdraw()
    # Создаем новое окно для регистрации
    upd_pass_window = tk.Toplevel(root)
    upd_pass_window.title("Обновление пароля")
    # Убираем рамку окна
    upd_pass_window.overrideredirect(True)
    # Set background color
    upd_pass_window.configure(bg="#4E443E")


    # Определяем начальные координаты мыши и окна
    start_x, start_y = 0, 0
    window_x, window_y = 0, 0

    # Создаем виджеты для ввода логина, пароля и адреса электронной почты
    pass_label = tk.Label(upd_pass_window, text="Обновление пароля:", bg="#4E443E", fg="#ffe7c9", font=("Helvetica", 16))
    old_pass_label = tk.Label(upd_pass_window, text="Старый пароль:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
    old_pass_entry = tk.Entry(upd_pass_window, bg="#FFF", fg="#000", font=("Helvetica", 14))
    new_pass_label = tk.Label(upd_pass_window, text="Новый пароль:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
    new_pass_entry = tk.Entry(upd_pass_window, bg="#FFF", fg="#000", font=("Helvetica", 14), show="*")
    new_pass_label_conf = tk.Label(upd_pass_window, text="Подтвердите новый пароль:", bg="#4E443E", fg="#FFCCBC", font=("Helvetica", 14))
    new_pass_entry_conf = tk.Entry(upd_pass_window, bg="#FFF", fg="#000", font=("Helvetica", 14))

    # Создаем кнопку "Зарегистрироваться" и функцию для ее обработки
    def do_pass_upd():

        user = login_entry.get()
        pass_hash = old_pass_entry.get()
        newHash = new_pass_entry.get()
        newHash_conf = new_pass_entry_conf.get()
        r_login = login_entry.get()

        if newHash != newHash_conf:
            print("Пароли не совпадают!")
            tk.messagebox.showerror("Error!", f"Пароли не совпадают!")
            return


        # Проверяем, что ввод корректный
        if not validate_input(user) or not validate_input(pass_hash):
            print("Некорректный ввод!")
            tk.messagebox.showerror("Error!", f"Поля содержат недопустимые символы!")
            return

        # Шифруем пароль
        salt = pass_hash  # случайная соль
        hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
        hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
        hash = hex_dig[:20]  # ограничиваем длину до 20 символов

        # Шифруем логин
        salt = user  # случайная соль
        hash_object = hashlib.sha1((user + salt).encode())  # создаем объект хеширования
        hex_dig = hash_object.hexdigest()  # получаем шестнадцатеричное представление хеша
        user = hex_dig[:20]  # ограничиваем длину до 20 символов

        # hash = base64.b64encode((user).encode('utf-8')).decode('utf-8')
        print(f"Pass Update: {user}, {r_login}, {hash}, {pass_hash}, {newHash}")

        base_address = "http://192.168.86.20:1111"
        params = {
            "user": user,
            "token": hash,
            "newToken": newHash,
            "r_login": r_login,
            "isPasswordUpdate": True
        }
        try:
            response = requests.get(base_address, params=params)
            if response.status_code == 200:
                try:
                    tk.messagebox.showinfo("Успешно!", f"Пароль успешно изменен!")
                except Exception as e:
                    tk.messagebox.showerror("Ошибка!", f"{e}")

            # Закрываем окно регистрации
            upd_pass_window.destroy()
            # Снова открываем окно логина
            root.deiconify()

        except requests.exceptions.RequestException as e:
            tk.messagebox.showerror("Ошибка!", f"Возникла ошибка: {e}")
        return 401

    # Обработчик нажатия кнопки мыши
    def start_drag(event):
        nonlocal start_x, start_y, window_x, window_y
        start_x = event.x_root
        start_y = event.y_root
        window_x = upd_pass_window.winfo_x()
        window_y = upd_pass_window.winfo_y()

    # Обработчик перемещения мыши
    def drag(event):
        nonlocal start_x, start_y, window_x, window_y
        dx = event.x_root - start_x
        dy = event.y_root - start_y
        new_x = window_x + dx
        new_y = window_y + dy
        upd_pass_window.geometry(f"+{new_x}+{new_y}")

    # Обработчик отпускания кнопки мыши
    def stop_drag(event):
        nonlocal start_x, start_y, window_x, window_y
        start_x, start_y, window_x, window_y = 0, 0, 0, 0

    # Привязываем обработчики событий
    upd_pass_window.bind("<ButtonPress-1>", start_drag)
    upd_pass_window.bind("<B1-Motion>", drag)
    upd_pass_window.bind("<ButtonRelease-1>", stop_drag)

    close_image = Image.open("close.png")
    close_image = close_image.resize((24, 24), resample=Image.LANCZOS)
    # устанавливаем прозрачность на максимальный уровень (255)
    #close_image.putalpha(0)
    close_image = ImageTk.PhotoImage(close_image)
    upd_pass_window.close_image = close_image
    close_button = tk.Button(upd_pass_window, image=upd_pass_window.close_image, command=upd_pass_window.destroy, bd=0,
                             highlightthickness=0, highlightcolor='#4E443E')

    #close_button.place(x=325 , y=0)


    push_pass_update_button = tk.Button(upd_pass_window, text="Обновить пароль", command=do_pass_upd)
    push_pass_update_button.config(bg="#D81B60", fg="#FFF", font=("Helvetica", 12))

    PADX = 10
    PADY = 10

    # Set up the grid layout for the labels, input fields, and buttons
    pass_label.grid(row=0, column=0, padx=PADX, pady=PADY, sticky="NE")
    close_button.grid(row=0, column=1, padx=PADX, pady=PADY, sticky="NE")

    old_pass_label.grid(row=1, column=0, padx=PADX, pady=PADY, sticky="W")
    old_pass_entry.grid(row=1, column=1, padx=PADX, pady=PADY, sticky="E")

    new_pass_label.grid(row=2, column=0, padx=PADX, pady=PADY, sticky="W")
    new_pass_entry.grid(row=2, column=1, padx=PADX, pady=PADY, sticky="E")

    new_pass_label_conf.grid(row=3, column=0, padx=PADX, pady=PADY, sticky="W")
    new_pass_entry_conf.grid(row=3, column=1, padx=PADX, pady=PADY, sticky="E")

    push_pass_update_button.grid(row=4, column=0, columnspan=2, padx=PADX, pady=PADY, sticky="EW")










# Подключаем функции к кнопкам
login_button.config(command=login_btn)
options_button.config(command=launch_options_btn)
check_updates_button.config(command=check_updates_btn)
play_button.config(command=play_btn)
register_button.config(command=register_def)
pass_update.config(command=upd_pass)




# Запускаем главный цикл приложения
root.mainloop()
