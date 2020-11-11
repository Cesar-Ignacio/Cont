#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

///FUNCIONES
void NuevoControl(void);
void ListarControles(void);
void BajaDeControl(void);
void BuscarControl(void);
void ModificarControl(void);
void Faltantes(void);
void RealizarBackup();
void Backup(void);
///FUNCONES AYUDA

int ContarRegistroDeArchivo(const char *,int);
int UbicacionDeRegistro(char *);


#endif // PROTOTIPOS_H_INCLUDED
