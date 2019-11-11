/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:43:16 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/11 17:21:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(void)
{
	char	texte[] = "La méthode du canard en plastique consiste à expliquer méticuleusement le code source que l'on a écrit à un collègue, à un simple passant, ou même à un objet inanimé comme un canard en plastique1,2. Le simple fait d'exprimer ses pensées à voix haute est censé aider à trouver les erreurs de programmation. Comme les réactions de l'interlocuteur ou son niveau de compréhension du problème n'ont aucune importance dans ce processus, on peut le remplacer par un canard en plastique. Lorsque le programmeur ou l'analyste explique un bout de code ou un algorithme qui est incorrect, il peut en effet se rendre compte de son erreur. La méthode du canard en caoutchouc exploite la dissonance cognitive en confrontant le concepteur au fait que le code qu'il a écrit ne correspond pas au code qu'il avait l'intention d écrire. L'avantage du canard en plastique sur un interlocuteur humain est que sa capacité d'écoute et sa patience sont sans limite. Son temps est aussi moins précieux que celui d'un consultant ou d'un collègue3. Le fait qu'il soit petit permet de le placer discrètement à côté d'un écran d'ordinateur. Ce principe est aussi très utile pour d'autres types de travaux. Par exemple, un projet devant être présenté à l'oral à l'aide d'un diaporama. Il suffit de décrire le projet à une personne ou à son canard en plastique pour le faire de la manière la plus simple possible, ce qui permet de trouver un fil conducteur naturel.";
	char	charset[] = "ae";
	char	*trimstring;

	trimstring = ft_strtrim(texte, charset);
	printf("\nResultat => %s\n", trimstring);
	return (0);
}
